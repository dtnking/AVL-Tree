#include "AvlString.h"

int StringCompare(char *nodeData,StringNode *refNode){
  if(strcmp(nodeData,refNode->data)>0)
    return 1;
  else if(strcmp(nodeData,refNode->data)<0)
    return -1;
  else
    return 0;
}
