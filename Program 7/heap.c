#include"heap.h"

Heap * initHeap(Data * d)					
{
	Heap * h = malloc(sizeof(Heap));			
	h->data = NULL;				
    h->data = d;						
	h->current_size = 1000;  //Since length is already given
	h->max_capacity = 1000;

	heapify(h);

	return h;
}

void heapify(Heap * h)
{ for (int i = (h->current_size / 2) - 1; i >= 0; i--)
	siftdown(h, i);
}

void siftdown(Heap * h, int pos)
{
     if ((pos < 0) || (pos >= h->current_size))
    {
      return;
    }

    while ((pos)< ((h->current_size)/2)){ 
     //Keep swapping until you get to a leaf
    int j = (2*pos)+1; //Get left child
    if (j+1 < h->current_size && (h->data[j].value > h->data[j+1].value)){
    	j++;
        }
                              // j is now index of child with greater value
    if (h->data[pos].value < h->data[j].value)
        { return;
        }	
    else{
    
    swap(h,pos,j);
    pos = j; 
    }	
    
                     
 }
 }
 
 void swap(Heap *h,int pos1,int pos2){
     	int temp = h->data[pos1].value;
			h->data[pos1].value = h->data[pos2].value;
			h->data[pos2].value = temp;
           
 }

Data removePriority(Heap * h){
//Check for empty heap

//Swap the root with last leaf
Data priority = h->data[0];
h->data[0] = h->data[h->current_size - 1];
h->data[h->current_size - 1] = priority;
h->current_size--;
siftdown(h,0);
return priority;

}

void deleteHeap(Heap * heap)					//Frees the memory
{
	free(heap);
    heap = NULL;
	
}




