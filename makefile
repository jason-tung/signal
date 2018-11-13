
all: main.o
	gcc -o doggy main.o
main.o: main.c
	gcc -c main.c
clean:
	rm *.o
run:
	./doggy