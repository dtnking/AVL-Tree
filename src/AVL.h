#ifndef _AVL_H
#define _AVL_H
#include "Node.h"
#include "Rotate.h"
#include "NodeVerifier.h"
#include "AvlInteger.h"
#include <stdio.h>

typedef int (Compare)(Node node,Node refNode);
int avlAdd(Node **rootPtr, Node *nodeToAdd,Compare compare);
int avlBalanceLeftTree(Node **rootPtr);
int avlBalanceRightTree(Node **rootPtr);
Node *_avlRemove(Node **rootPtr,int delData, int *heightFlag);
Node *avlRemove(Node **rootPtr,int delData);
Node *findNearest(Node **rootPtr,int *heightFlag);


#endif // _AVL_H
