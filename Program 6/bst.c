#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int nodeIndex = 0;

Node *newNode(Data value, Node *parentNode)
{
    parentNode = malloc(sizeof(Node));
    parentNode->data = value;
    parentNode->left = NULL;
    parentNode->right = NULL;
    parentNode->parent = NULL;
    return parentNode;
}

Tree *newTree()
{

    Tree *t = malloc(sizeof(Tree));
    t->root = NULL;
    t->insert = insertTree;
    t->search = searchTree;
    t->sort = sortTree;
    t->clone = clone;
    t->compare = compareTree;
    t->delete = deleteTree;
    t->removeData = removeData;
    return t;
}

Data *insertTree(Tree *BstTree, Data value)
{

    if (BstTree->root == NULL)
        BstTree->root = newNode(value, NULL);
    else
        return insertNode(BstTree->root, value);
    if (BstTree->root != NULL)
        return &(BstTree->root->data);
    else
        return NULL;
}

Data *insertNode(Node *n, Data value)
{
    Node *newT = NULL;

    if (value.value < n->data.value)
    {
        if (n->left == NULL)
        {
            newT = newNode(value, n);
            n->left = newT;
            newT->parent = n;
            return &newT->data;
        }
 
        else
            return insertNode(n->left, value);
    }
    else if (value.value > n->data.value)
    {
    if (n->right == NULL)
        {
            newT = newNode(value, n);
            n->right = newT;
            newT->parent = n;
            return &newT->data;
        }
        else
            return insertNode(n->right, value);
    }
 
    else
        return &newT->data;
}

void inOrderTSorting(Node *node, Data *value)
{
    if (node != NULL)
    {
        inOrderTSorting(node->left, value);
        value[nodeIndex] = node->data;
        nodeIndex++;
        inOrderTSorting(node->right, value);
    }
}

void sortTree(Tree *BstTree, Data *value)
{
    if (BstTree->root != NULL)
        inOrderTSorting(BstTree->root, value);
}

Tree *clone(Tree *BstTree)
{
    Tree *newTreeClone = NULL;

    if (BstTree->root != NULL)
    {
        newTreeClone = newTree();
        cloneTree(BstTree->root, newTreeClone);
    }
    return newTreeClone;
}

void cloneTree(Node *node, Tree *BstTree)
{
    if (node != NULL)
    {
        insertTree(BstTree, node->data);
        cloneTree(node->left, BstTree);
        cloneTree(node->right, BstTree);
    }
}

Data *searchTree(Tree *BstTree, Data value)
{
    Node *currentNode = NULL;

    if (BstTree->root == NULL)
        return NULL;
    
    if (BstTree->root != NULL)
        currentNode = searchNode(BstTree->root, value);

    if (currentNode != NULL)
        return &(currentNode->data);
}

Node *searchNode(Node *Searchn, Data value)
{
    if (Searchn == NULL)
        return Searchn;

    if (Searchn->data.value == value.value)
        return Searchn;

    if (value.value < Searchn->data.value)
        return searchNode(Searchn->left, value);
 
    else
        return searchNode(Searchn->right, value);
}

int compareTree(Tree *first, Tree *second)
{
    int compareValue = 0;

    if (first != NULL && second != NULL)
        compareValue = compareTreeNode(first->root, second->root);

    return compareValue;
}

int compareTreeNode(Node *firstNode, Node *secondNode)
{
    int cmp = 0;

    if (firstNode != NULL && secondNode != NULL)
    {
        if (firstNode->data.value == secondNode->data.value)
            cmp = 1;

        compareTreeNode(firstNode->left, secondNode->left);
        compareTreeNode(firstNode->right, secondNode->right);
    }

    return cmp;
}

void deleteTree(Tree *BstTree)
{
    if (BstTree->root != NULL)
        deleteTreeFunction(BstTree->root);

    free(BstTree);
}

void deleteTreeFunction(Node *Deleten)
{
    if (Deleten != NULL)
    {
        deleteTreeFunction(Deleten->left);
        deleteTreeFunction(Deleten->right);
        removeLeaf(Deleten);
    }
}

void removeData(Tree *BstTree, Data value)
{
    Node *Deleten = deleteSearch(BstTree, value);
    if (Deleten != NULL)
    {
    if (Deleten->left == NULL && Deleten->right == NULL)
        {
    if (Deleten == BstTree->root)
        {
        free(BstTree->root);
        BstTree->root = NULL;
        }
        else
        removeLeaf(Deleten);
        }
        else if (Deleten->left == NULL || Deleten->right == NULL)
        {
if (Deleten == BstTree->root){
    if (Deleten->left == NULL)
    {
    BstTree->root = Deleten->right;
    Deleten->right = NULL;
    }
else if (Deleten->right == NULL)
    {
    BstTree->root = Deleten->left;
Deleten->left = NULL;
 }
  free(Deleten);
Deleten = NULL;
            }

            else
                shortCircuit(Deleten);
        }

        else
            promotion(Deleten);
    }
}

void removeLeaf(Node *removen)
{
    if (removen->parent == NULL)
    {
        free(removen);
        removen = NULL;
    }
    else
    {
        if (removen == removen->parent->left)
            removen->parent->left = NULL;

        else
            removen->parent->right = NULL;

        free(removen);
        removen = NULL;
    }
}

void shortCircuit(Node *shortn)
{
    if (shortn->parent == NULL)
    {
        if (shortn->left == NULL)
            shortn->right = NULL;

        else if (shortn->right == NULL)
            shortn->left = NULL;

        free(shortn);
        shortn = NULL;
    }
    else
    {
        if (shortn == shortn->parent->left)
        {
            if (shortn->left == NULL)
            {
                shortn->parent->left = shortn->right;
                shortn->right->parent = shortn->parent;
            }
            else 
            if (shortn->right == NULL)
            {
                shortn->parent->left = shortn->left;
                shortn->left->parent = shortn->parent;
            }           
        }
        else if (shortn == shortn->parent->right)
        {
            if (shortn->left == NULL)
            {
                shortn->parent->right = shortn->right;
                shortn->right->parent = shortn->parent;
            }
            else if (shortn->right == NULL)
            {
                shortn->parent->right = shortn->left;
                shortn->left->parent = shortn->parent;
            }
        }
        free(shortn);
        shortn = NULL;
    }
}

void promotion(Node *promoten)
{
    Node *minRightNode = findMinRightNode(promoten);

    promoten->data = minRightNode->data;

    if (minRightNode->right == NULL)
        removeLeaf(minRightNode);

    else
        shortCircuit(minRightNode);
}

Node *findMaxLeftNode(Node *maxL)
{
    if (maxL->left == NULL)
        return maxL;
    
    else
    {
        maxL = maxL->left;

        while (maxL->right != NULL)
            maxL = maxL->right;
    
    }

    return maxL;
}

Node *findMinRightNode(Node *minR)
{
    if (minR->right == NULL)
        return minR;

    else
    {
        minR = minR->right;

        while (minR->left != NULL)
            minR = minR->left;

    }

    return minR;
}

Node *deleteSearch(Tree *BstTree, Data value)
{
    if (BstTree->root == NULL)
        return NULL;

    else
        return deleteSearchNode(BstTree->root, value);
}

Node *deleteSearchNode(Node *Deleten, Data value)
{
    if (Deleten == NULL)
        return NULL;
    else
    {
        if (Deleten->data.value == value.value)
            return Deleten;

        else if (Deleten->data.value > value.value)
            searchNode(Deleten->left, value);

        else if (Deleten->data.value < value.value)
            searchNode(Deleten->right, value);

        else
            return NULL;
    }
}