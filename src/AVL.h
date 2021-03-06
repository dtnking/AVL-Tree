#ifndef _AVL_H
#define _AVL_H
#include "Node.h"
#include "Rotate.h"
#include "NodeVerifier.h"
#include "AvlInteger.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef int (*Compare)(void *data,Node *refNode);
int _avlAdd(Node **rootPtr, Node *nodeToAdd,Compare compare);
void avlAdd(Node **root, Node *nodeToAdd, Compare compare);
int avlBalanceLeftTree(Node **rootPtr);
int avlBalanceRightTree(Node **rootPtr);
Node *_avlRemove(Node **rootPtr,int delData,  Compare compare,int *heightFlag);
Node *avlRemove(Node **rootPtr,int delData, Compare compare);
Node *findNearest(Node **rootPtr,int *heightFlag);


#endif // _AVL_H
