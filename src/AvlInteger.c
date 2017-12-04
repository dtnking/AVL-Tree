#include "AvlInteger.h"

int IntegerCompare(int nodeData,intNode *refNode){

  if(nodeData > refNode->data)
    return 1;
  else if(nodeData < refNode->data)
    return -1;
  else
    return 0;
}
