#include "AVL.h"
#include "unity.h"
#include <malloc.h>
#include <stdarg.h>
#include <stdio.h>

/** ------------------------------------------------------------------
 *           before         |        |        after         |
 *                    grand |        |                grand | height
 *     root   child   child | action | root   child   child | change
 *  ------------------------------------------------------------------
 *      +2     +1       x   |   L    |  0       0       x   | yes
 *      +2      0       x   |   L    |  1      -1       x   | no
 *      +2     -1      -1   |   RL   |  0       1       0   | yes
 *      +2     -1       0   |   RL   |  0       0       0   | yes
 *      +2     -1      +1   |   RL   | -1       0       0   | yes
 *      -2     -1       x   |   R    |  0       0       x   | yes
 *      -2      0       x   |   R    | -1       1       x   | no
 *      -2     +1      +1   |   LR   |  0      -1       0   | yes
 *      -2     +1       0   |   LR   |  0       0       0   | yes
 *      -2     +1      -1   |   LR   |  1       0       0   | yes
 *  -----------------------------------------------------------------
 */
   int heightChanged;
int avlAdd(Node **rootPtr, Node *nodeToAdd){
  char *error;
  if(*rootPtr == nodeToAdd){

    error = createMessage("Error, Adding same node");
  }else{
  if(*rootPtr == NULL){
    *rootPtr = nodeToAdd;
    return 1;
  } else {
    if ((*rootPtr)->data > nodeToAdd->data){
        heightChanged = avlAdd(&(*rootPtr)->left,nodeToAdd);
        if(heightChanged==1){
          (*rootPtr)->balanceFactor -= 1 ;
          if((*rootPtr)->balanceFactor==0)
            return 0;
        }
        else
          return 0;

      if((*rootPtr)->balanceFactor !=-2)
        return 1;

      if(avlBalanceRightTree(&(*rootPtr))==1)
        return 0;
      else
        return 1;
    }
    else{
        heightChanged = avlAdd(&(*rootPtr)->right,nodeToAdd);
        if(heightChanged==1){
          (*rootPtr)->balanceFactor += 1;
          if((*rootPtr)->balanceFactor==0)
            return 0;
          }
        else
          return 0;
      if((*rootPtr)->balanceFactor != 2)
        return 1;

      if(avlBalanceLeftTree(&(*rootPtr))==1)
        return 0;
      else
        return 1;
      }
    }
  }
}

*Node *avlRemove(Node **rootPtr, int data){
  int heightChange;
  Node *dataRemove = _avlRemove(rootPtr,data,heightChange);
    if(dataRemove == NULL)
      printf("Couldn't find the node");
    else
      return dataRemove;
}

Node *_avlRemove(Node **rootPtr,int data, int *heightFlag){
  int temp;
  if(*rootPtr == NULL)
    return NULL;

  else{
    if(*rootPtr->data == data){
      if(*rootPtr->left == NULL && *rootPtr->right == NULL){
      temp = *rootPtr;
      *rootPtr = NULL;
      return temp;
    }
      else if(*rootPtr->left == NULL){
        temp = *rootPtr;
        *rootPtr->balanceFactor -= 1;
        *rootPtr = *rootPtr->right;
        *heightFlag = 1;
        return temp;
      }
      else if(*rootPtr->left == NULL){
        temp = *rootPtr;
        *rootPtr->balanceFactor += 1;
        *rootPtr = *rootPtr->left;
        *heightFlag = 1;
        return temp;
      }
      else{
        temp = *rootPtr;
        *rootPtr = findNearest((*rootPtr)->right);
        *heightFlag = 1;
        temp->balanceFactor = (*rootPtr)->balanceFactor;
        temp->left = (*rootPtr)->left;
        temp->right = (*rootPtr)->right;
        (*rootPtr) = temp;
      }
    }
    else{
      if((*rootPtr)->data > data){
        avlRemove((*rootPtr)->left,data);
        if(heightChanged == 1){
          (*rootPtr)->balanceFactor  +=1;
            if((*rootPtr)->balanceFactor != 0 && (*rootPtr)->balanceFactor != 2)

      }
    }

  }
}
/*
Node *_avlRemove(Node **rootPtr, int data,int *heightFlag){
  Node *temp;
  int heightChanged;
  if(*rootPtr==NULL)
    return NULL;
  if ((*rootPtr)->data == data){
    if(((*rootPtr)->left == NULL) && ((*rootPtr)->right == NULL)){
      *rootPtr = NULL;
      return rootPtr;
      }else{
        if((*rootPtr)->right == NULL){
          temp = (*rootPtr);
          (*rootPtr)->balanceFactor += 1;
          (*rootPtr)->left->balanceFactor = (*rootPtr)->balanceFactor;
          (*rootPtr) = (*rootPtr)->left;
          *heightFlag = 1;
          return temp;
        }
        else if((*rootPtr)->left == NULL){
          temp = (*rootPtr);
          (*rootPtr)->balanceFactor -= 1;
          (*rootPtr)->right->balanceFactor = (*rootPtr)->balanceFactor;
          (*rootPtr) = (*rootPtr)->right;
          *heightFlag = 1;
          return temp;
        }
        else {
          temp = findNearest((*rootPtr)->right);
          //avlRemove(rootPtr,temp->data);
          temp->balanceFactor = (*rootPtr)->balanceFactor;
          temp->left = (*rootPtr)->left;
          temp->right = (*rootPtr)->right;
          (*rootPtr) = temp;
        }
      }

      if((*rootPtr)->balanceFactor != 0)
        *heightFlag = 0;
      *heightFlag = 1;
  }
  else{
    if((*rootPtr)->data > data){
      *heightFlag = avlDelete(&(*rootPtr)->left,data);
      if(heightChanged == 1){
        (*rootPtr)->balanceFactor  +=1;
          if((*rootPtr)->balanceFactor != 0 && (*rootPtr)->balanceFactor != 2)
            return 0;
      }else
        return 0;
      return avlBalanceLeftTree(&(*rootPtr));
    }else{
      heightChanged = avlDelete(&(*rootPtr)->right,data);
      if(heightChanged == 1){
        (*rootPtr)->balanceFactor  -=1;
          if((*rootPtr)->balanceFactor != 0 && (*rootPtr)->balanceFactor != -2)
            return 0;
      }else
        return 0;
      return avlBalanceRightTree(&(*rootPtr));
    }
  }
}

*/
Node *findNearest(Node *node){
  Node *temp;
  if(node->left!=NULL)
    return findNearest(node->left);
  else{
    if(node->right!=NULL){
      temp = node;
      node = node->right;
      node->balanceFactor -= 1;
      return temp;
    }
    else{
      temp = node;
      node = NULL;
      return temp;
    }
  }
}

int avlBalanceLeftTree(Node **rootPtr){
  Node *node = *rootPtr;

  if((*rootPtr)->balanceFactor  <= 1)
    return 1;

  if(node->right->balanceFactor == 1 ){
    node->balanceFactor = 0;
    node->right->balanceFactor = 0;
    *rootPtr = rotateLeft(*rootPtr);
    return 1;
    }
  else if(node->right->balanceFactor == 0){
    node->balanceFactor = 1;
    node->right->balanceFactor = -1;
    *rootPtr = rotateLeft(*rootPtr);
    return 0;
    }
  else if(node->right->balanceFactor == -1){
    if(node->right->left->balanceFactor == -1){
      node->balanceFactor = 0;
      node->right->balanceFactor = 1;
      node->right->left->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      return 1;
      }
    else if(node->right->left->balanceFactor == 0){
      node->balanceFactor = 0;
      node->right->balanceFactor = 0;
      node->right->left->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      return 1;
      }
    else if(node->right->left->balanceFactor == 1){
      node->balanceFactor = -1;
      node->right->balanceFactor = 0;
      node->right->left->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      return 1;
      }
    }
}

int avlBalanceRightTree(Node **rootPtr){
  Node *node = *rootPtr;



  if((*rootPtr)->balanceFactor >= -1)
    return 1;


  if(node->left->balanceFactor == -1 ){
    node->balanceFactor = 0;
    node->left->balanceFactor = 0;
    *rootPtr = rotateRight(*rootPtr);
    return 1;
    }
  else if(node->left->balanceFactor == 0){
    node->balanceFactor = -1;
    node->left->balanceFactor = 1;
    *rootPtr = rotateRight(*rootPtr);
    return 0;
    }
  else if(node->left->balanceFactor ==1){
    if(node->left->right->balanceFactor == 1){
      node->balanceFactor = 0;
      node->left->balanceFactor = -1;
      node->left->right->balanceFactor = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      return 1;
      }
    else if(node->left->right->balanceFactor == 0){
      node->balanceFactor = 0;
      node->left->balanceFactor = 0;
      node->left->right->balanceFactor = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      return 1;
      }
    else if(node->left->right->balanceFactor == -1){
      node->balanceFactor = 1;
      node->left->balanceFactor = 0;
      node->left->right->balanceFactor = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      return 1;
      }

  }
  return 0;
}
