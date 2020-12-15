CC=gcc
CFLAGS=-g
.PHONY: all defuseTheBomb checkmem clean
all: defuseTheBomb checkmem clean

defuseTheBomb:bomb.o defuseMe.o hidden.o
	$(CC) $(CFLAGS) bomb.o defuseMe.o hidden.o -o defuseTheBomb 
	
checkmem:program3B.c
	$(CC) $(CFLAGS) -c program3B.c -o program3B.o
	$(CC) $(CFLAGS) program3B.o -o checkmem
	valgrind ./checkmem

clean:trash.sh
	sh trash.sh bomb.o defuseMe.o program3B.o

        


