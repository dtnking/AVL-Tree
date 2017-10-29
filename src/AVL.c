#include "AVL.h"

int avlAdd(Node **rootPtr, Node *nodeToAdd){
  if(*rootPtr == NULL){
    *rootPtr = nodeToAdd;
    return *rootPtr;
  } else {
    if ((*rootPtr)->data > nodeToAdd->data){
        Node *temp = (*rootPtr)->left;
        (*rootPtr)->left = avlAdd(&temp,nodeToAdd);
      }
    else if((*rootPtr)->data < nodeToAdd->data){
        Node *temp = (*rootPtr)->right;
        (*rootPtr)->right = avlAdd(&temp,nodeToAdd);
      }
    else
      return *rootPtr;
  }
}
