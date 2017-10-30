#ifndef _AVL_H
#define _AVL_H
#include "Node.h"
#include "Rotate.h"
#include <stdio.h>

Node *avlAdd(Node **rootPtr, Node *nodeToAdd);
int avlBalanceLeftTree(Node **rootPtr);
int avlBalanceRightTree(Node **rootPtr);


#endif // _AVL_H
