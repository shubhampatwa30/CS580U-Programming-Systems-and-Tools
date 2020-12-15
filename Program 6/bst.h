#include <stdio.h>
#include <stdlib.h>

#ifndef DATA
#define DATA

typedef struct Data
{
    int value;
} Data;

typedef struct Node
{
    struct Data data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

typedef struct Tree
{
    Node *root;
    Data *(*insert)(struct Tree *t, Data);
    Data *(*search)(struct Tree *bst, Data value);
    void (*sort)(struct Tree *, Data *);
    int (*compare)(struct Tree *t, struct Tree *copy);
    struct Tree *(*clone)(struct Tree *t);
    void (*delete)(struct Tree *bst);
    void (*removeData)(struct Tree *bst, Data value);
}Tree; 

Node *newNode(Data d, Node *parent);
Tree *newTree();
Data *insertNode(Node * node, Data value);
Node * searchNode(Node * node, Data value);
void sortTree(struct Tree *tree, Data * data);
int compareTree(struct Tree *t, struct Tree *copy);
Tree *clone(Tree *t);
void deleteTree(struct Tree *bst);
void removeData(Tree *bst, Data value);


Data *insertTree(struct Tree *t,Data);
Data *searchTree(struct Tree *bst, struct Data value);
void cloneTree(Node *node, Tree *tree);
int compareTreeNode(Node *first, Node *second);
void shortCircuit(Node *node);
void promotion(Node *node);
Node *findMaxLeftNode(Node *node);
Node *findMinRightNode(Node *node);
Node *deleteSearch(Tree *tree, Data data);
Node *deleteSearchNode(Node *node, Data data);
void deleteTreeFunction(Node *node);
void removeLeaf(Node *node);
#endif