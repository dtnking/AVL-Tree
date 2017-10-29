#include "AVL.h"

Node *avlAdd(Node **rootPtr, Node *nodeToAdd){
  if(*rootPtr == NULL){
    *rootPtr = nodeToAdd;
    return *rootPtr;
  } else {
    if ((*rootPtr)->data > nodeToAdd->data){
        (*rootPtr)->left = avlAdd(&(*rootPtr)->left,nodeToAdd);
      }
    else if((*rootPtr)->data < nodeToAdd->data){
        (*rootPtr)->right = avlAdd(&(*rootPtr)->right,nodeToAdd);
      }
  }
  return *rootPtr;
}
