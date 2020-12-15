all: program8

program8: program8.c
	gcc -lm program8.c -o program8

run: all
	./program8

checkmem: all
	valgrind ./program8

clean:
	rm -f *.o program8