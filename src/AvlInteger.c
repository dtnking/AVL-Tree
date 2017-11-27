#include "AvlInteger.h"

int IntegerCompare(int *nodeData,Node *refNode){
  if(*nodeData > refNode->data)
    return 1;
  else if(*nodeData < refNode->data)
    return -1;
  else
    return 0;
}
