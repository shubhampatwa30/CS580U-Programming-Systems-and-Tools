#include "heap.c"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
	

	printf("\n\n\tCreating an array of 1000 Data objects with random integer values between 1-1000 and inserting into Data Array.\n\n\n");

	int i;
	Data data[1000];

	for(i = 0; i < 1000; i++)
	{
		data[i] = (Data){((rand() % 1000)+1)};
	//	printf("%d\n \t",data[i]);
	}
	printf("\t-----------------------------------\n");
    printf("\t Test 1 : Create a heap using InitHeap \n");
    printf("\t-----------------------------------\n");
	printf("\tCreating a heap using initHeap funciton \n\n\n");

	Heap * h = initHeap(data);

	printf("\t--- Test 1 passed... ---\n\n\n");
	printf("\t-----------------------------------\n");
    printf("\t- Test 2: Remove Priority Value from Heap -\n");
    printf("\t-----------------------------------\n");
	printf("\n\n\tRemoving the priority values from the heap...\n\n\n");

	Data removedPriority = data[0];

	for(i = 0; i < 1000; i++)
	{
		Data CurrentPriority = removePriority(h);
		assert(removedPriority.value <= CurrentPriority.value);
		removedPriority = CurrentPriority;
	}

	printf("\t--- Test 2 passed... ---\n\n\n");
	
	printf("\t-----------------------------------\n");
    printf("\t- Clearing memory for valgrind by deleting heap-\n");
    printf("\t Please check valgrind for memory leak !\n");
	deleteHeap(h);
	printf("\tDONE !!\n\n\n");
	return 0;
}
