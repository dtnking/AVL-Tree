#ifndef _AVLSTRING_H
#define _AVLSTRING_H

#include "AVL.h"
#include "Node.h"

#define avlAddString(r,n)     avlAdd((Node **)(r),(Node *)(n),(Compare *)(StringCompare))
#define avlRemoveString(r,n)  avlRemove((Node **)(r),(int )(n),(Compare *)(StringCompare))

int StringCompare(char* nodeData,StringNode *refNode);

#endif // _AVLSTRING_H
