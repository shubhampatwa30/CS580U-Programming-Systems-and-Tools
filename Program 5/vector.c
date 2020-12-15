#ifndef vector_c
#define vector_c
#include"vector.h"
#include"data.h"
#include <assert.h>
#include<stdlib.h>

Vector * newVector()
{	//initialising values
	Vector * vec = malloc(sizeof(Vector));
	vec->max_size = 0;
	vec->current_size = 0;
	vec->data = malloc(sizeof(Data)*(vec->max_size));
	vec->data=NULL;
	vec->insert=insertVector;
	vec->read=readVector;
	vec->remove=removeVector;
	vec->delete=deletevector;
	return vec;
}

void insertVector(struct Vector * array, int index, Data value)
{
	while(index>=array->max_size){
		array->max_size = (2*(index))+1;
	 	array->data = realloc(array->data,sizeof(Data)*(array->max_size));
		
	}
	
	array->data[index].value = value.value;
	if(array->current_size<index)
	array->current_size=index+1;
	
}

void removeVector(Vector * array, int index){
	int i;
	for(i=index;i<array->current_size-1;i++)
	{
		array->data[i]=array->data[i+1];	
	}
	array->current_size = array->current_size-1;
}

Data * readVector(Vector * array, int index){
	if(index>array->max_size){
		return NULL;
	}
	else
	{
		if(array->data[index].value=='\0'){
			
			array->data[index].value=-1;
			return &array->data[index];
	}
		else{
			return &array->data[index];
	}
	}
}

void * deletevector(Vector * array){
	free(array->data);
	free(array);
	return NULL;
}

#endif
