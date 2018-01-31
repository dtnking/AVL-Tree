#include "AvlInteger.h"

int IntegerCompare(int nodeData,intNode *refNode){
  int refData = (int)refNode->data;
  if(nodeData > refData)
    return 1;
  else if(nodeData < refData)
    return -1;
  else
    return 0;
}
