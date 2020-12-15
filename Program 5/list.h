#ifndef list_h
#define list_h
#include"data.h"
typedef struct Node {
	struct Node *prev;
	struct Node *next;
	Data data;
}Node;
typedef struct List{
	int current_size;
	struct Node *head,*tail;

	void (*insert)(struct List * list,int index, Data value);
	Data * (*read)(struct List * list, int Data);
	void (*remove)(struct List * list, int Data);
	void (*delete)(struct List * list);
}List;

List *newList();
void insertList(struct List * list, int index, Data value);
void removeData(struct List * list, int index);
Data * readData(struct List * list, int index);
void deletelist(struct List * list);

#endif
