CC=gcc

all: program6.c
	$(CC) -g program6.c -o program6
run: all
	./program6
checkmem: program6
	valgrind ./program6
clean:
	rm program6