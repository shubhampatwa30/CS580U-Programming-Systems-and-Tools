#ifndef list_c
#define list_c
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"list.h"
#include<assert.h>

List *newList()
{
	List *newList  = malloc(sizeof(List));
	newList->current_size = 0;
	newList->head = NULL;
	newList->tail = NULL;
	newList->insert=insertList;
	newList->read=readData;
	newList->remove=removeData;
	newList->delete=deletelist;
	return newList;
}

void insertList(List * list, int index, Data value){
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	temp->data = value;
	if(list->head==NULL){
		list->head = temp;
		list->head->next = NULL;
		list->head->prev=NULL;
		list->tail = list->head;
		list->current_size++;
	}
	else
	{
		
		temp->prev = list->tail;
		temp->next = NULL;
		list->tail->next = temp;
		list->tail = temp;
		
		list->current_size++;


	}

	
	
			
}
void removeData(List * list, int index){
		if(index<list->current_size)
	{	struct Node *p,*temp;
		temp = (Node*)malloc(sizeof(Node));
		int i;
		p=list->head;

		for(i=0;i<index;i++){
			p = p->next;
			
		}
		if(list->head== list->tail)
		{list->head = NULL;
		list->tail = NULL;
		list->current_size--;
		}
		else if(list->head==p){
list->head = list->head->next;
			list->head->prev = NULL;
			list->current_size--;
		}
		else if(list->tail == p){
		list->tail = list->tail->prev;
		list->tail->next = NULL;
		list->current_size--;
		}

		
		
		else {temp->next = p->next;
			temp->prev= p->prev;
			p->next->prev = temp->prev;
			p->prev->next = temp->next;
			list->current_size--;
			}
	}
	else{
		return;
	}


}
void deletelist(List * list)
{	
while(list->current_size!=0)
	{	list->remove(list,0);
	
	}
	free(list->head);
	free(list);
}

Data * readData(List * list, int index){
	if(index>=list->current_size){
		return NULL;
	}
	else{
		struct Node *p;
		p=list->head;
		int i;
		for(i=0;i<index;i++){
			p=p->next;
		}
		return &p->data;
	}
}


#endif
