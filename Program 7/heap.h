#ifndef heap_h
#define heap_h
#include <stdio.h>
#include <stdlib.h>

typedef struct Data{
    int value;

}Data;

typedef struct Heap{
    Data *data;
    int max_capacity;
    int current_size;
   

}Heap;


Data removePriority(Heap * h);
void swap(Heap *h,int pos1,int pos2);
void siftdown(Heap * h, int pos);
void heapify(Heap * h);
Heap * initHeap(Data * d);
void deleteHeap(Heap * heap);

#endif
