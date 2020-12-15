#ifndef vector_h
#define vector_h
#include"data.h"
typedef struct Vector{
		int max_size; //initialize to 10
		int current_size; //initialize to 0
		Data * data; //malloc(..)
		void (*insert) (struct Vector * array, int index, Data value);
 	void (*remove) (struct Vector * array, int index);
	Data * (*read) (struct Vector * array, int index);
	void *(*delete)(struct Vector * array);
}Vector;

Vector * newVector();

void insertVector(struct Vector * array, int index, Data value);
void removeVector(struct Vector * array, int index);
Data * readVector(struct Vector * array, int index);
void * deletevector(struct Vector * array);

#endif
