CC=gcc
CFLAGS=-g
.PHONY: all run checkmem clean

all:vector.c vector.h list.c list.h profile.c profile.h data.h program5.c
	$(CC) $(CFLAGS) program5.c -o run
	
run : run
	./run
	
	
checkmem: all 
	valgrind ./run
clean: 
	rm run



        


