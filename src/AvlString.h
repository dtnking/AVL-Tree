#ifndef _AVLSTRING_H
#define _AVLSTRING_H

#include "AVL.h"
#include "Node.h"

#define avlAddString(r,n)     avlAdd((Node **)(r),(Node *)(n),(Compare *)(StringCompare))


int StringCompare(int nodeData,Node *refNode);

#endif // _AVLSTRING_H
