#include "AvlString.h"

int StringCompare(char *nodeData,Node *refNode){
  StringNode *strRefNode = (StringNode *)refNode;

  if(nodeData > strRefNode->data)
    return 1;
  else if(nodeData < strRefNode->data)
    return -1;
  else
    return 0;
}
