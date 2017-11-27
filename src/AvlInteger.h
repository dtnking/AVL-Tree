#ifndef _AVLINTEGER_H
#define _AVLINTEGER_H
#include "AVL.h"
#include "Node.h"

#define avlAddInteger(r,n)     avlAdd((Node **)(r),(Node *)(n),(Compare *)(IntegerCompare))


int IntegerCompare(int *nodeData,Node *refNode);

#endif // _AVLINTEGER_H
