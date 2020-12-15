CC=gcc
CFLAGS=-g
.PHONY: all run checkmem clean

all: program7.c
	$(CC) $(CFLAGS) program7.c -o program7
	
run : program7
	./program7
	
	
checkmem: all 
	valgrind ./program7
clean: 
	rm program7



        


