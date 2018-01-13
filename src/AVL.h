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
int avlAdd(Node **rootPtr, Node *nodeToAdd,Compare compare);
int avlBalanceLeftTree(Node **rootPtr,int *heightFlag);
int avlBalanceRightTree(Node **rootPtr,int *heightFlag);
Node *_avlRemove(Node **rootPtr,int delData,  Compare compare,int *heightFlag);
Node *avlRemove(Node **rootPtr,int delData, Compare compare);
Node *findNearest(Node **rootPtr,int *heightFlag);


#endif // _AVL_H
