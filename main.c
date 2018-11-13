
#include <signal.h>
#include <printf.h>
#include <zconf.h>
#include <fcntl.h>
#include <stdlib.h>


static void sig_handler(int signo){
    if (signo == SIGINT){
        printf("writing into log");
        int file = open("log", O_CREAT | O_APPEND | O_WRONLY);
        char boi[] = "program exited because of sigint\n";
        printf("program exiting. writing into log\n");
        write(file, boi, sizeof(boi));
        close(file);
        exit(0);
    }
    else if (signo == SIGUSR1){
        printf("my parent's pid: %d\n",getppid());
    }
    else{
        printf("what\n");
    }
}

int main(){
    signal(SIGINT, sig_handler);
    signal(SIGUSR1, sig_handler);
    kill(getpid(), SIGUSR1);
    while(1){
        printf("my proccess id: %d\n", getpid());
        sleep(1);
    }
    return 0;
}