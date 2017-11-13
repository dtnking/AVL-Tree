#ifndef _AVL_H
#define _AVL_H
#include "Node.h"
#include "Rotate.h"
#include <stdio.h>

int avlAdd(Node **rootPtr, Node *nodeToAdd);
int avlBalanceLeftTree(Node **rootPtr);
int avlBalanceRightTree(Node **rootPtr);
int avlDelete(Node **rootPtr, Node *nodeToDelete);  //Node *avlRemove(Node **rootPtr,int data)
Node *findNearest(Node *node);


#endif // _AVL_H
