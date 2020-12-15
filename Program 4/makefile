CC=gcc
CFLAGS=-g
.PHONY: all run checkmem clean

all:program4.c tournament.c tournament.h
	$(CC) $(CFLAGS) program4.c -o run
	
run : run
	./run
	
	
checkmem: all 
	valgrind ./run
clean: 
	rm run



        


