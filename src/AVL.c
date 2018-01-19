#include "AVL.h"
#include "unity.h"
#include <malloc.h>
#include <stdarg.h>
#include <stdio.h>
#include "Exception.h"
#include "CException.h"

/** ------------------------------------------------------------------
 *           before         |        |        after         |
 *                    grand |        |                grand | height
 *     root   child   child | action | root   child   child | change
 *  ------------------------------------------------------------------
 *      +2     +1       x   |   L    |  0       0       x   | yes   /
 *      +2      0       x   |   L    |  1      -1       x   | no    /
 *      +2     -1      -1   |   RL   |  0       1       0   | yes   /
 *      +2     -1       0   |   RL   |  0       0       0   | yes   /
 *      +2     -1      +1   |   RL   | -1       0       0   | yes   /
 *      -2     -1       x   |   R    |  0       0       x   | yes   /
 *      -2      0       x   |   R    | -1       1       x   | no    /
 *      -2     +1      +1   |   LR   |  0      -1       0   | yes   /
 *      -2     +1       0   |   LR   |  0       0       0   | yes   /
 *      -2     +1      -1   |   LR   |  1       0       0   | yes   /
 *  -----------------------------------------------------------------
 */

void avlAdd(Node **root, Node *nodeToAdd, Compare compare){
  _avlAdd(root,nodeToAdd, compare);
}

int _avlAdd(Node **rootPtr, Node *nodeToAdd,Compare compare){
  int heightChanged;
  char *error;

  if(*rootPtr == NULL){
    *rootPtr = nodeToAdd;
    return 1;
  } else {
    if (compare((void *)(intptr_t)nodeToAdd->data,*rootPtr)== -1){
        heightChanged = _avlAdd(&(*rootPtr)->left,nodeToAdd,compare);
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
    else if(compare((void *)(intptr_t)nodeToAdd->data,*rootPtr)== 1){
        heightChanged = _avlAdd(&(*rootPtr)->right,nodeToAdd,compare);
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
      else
        Throw(createException("Node to add is already exist", NODE_ADD_EXIST));
    }
}

Node *avlRemove(Node **rootPtr, int delData, Compare compare){
  int heightChange;
  Node *dataRemove = _avlRemove(rootPtr,delData,compare,&heightChange);
    if(dataRemove == NULL)
      Throw(createException("Couldn't find the node", NODE_NA));
    else
      return dataRemove;
}

Node *_avlRemove(Node **rootPtr,int delData,Compare compare, int *heightFlag){
  Node *temp;
  if(*rootPtr == NULL)
    return NULL;

  else{
    if((*rootPtr)->data == delData){
      if((*rootPtr)->left == NULL && (*rootPtr)->right == NULL){
      temp = *rootPtr;
      *rootPtr = NULL;
      *heightFlag = 1;
      return temp;
      }
      else if((*rootPtr)->left == NULL){
        temp = *rootPtr;
        (*rootPtr)->balanceFactor -= 1;
        *rootPtr = (*rootPtr)->right;
        *heightFlag = 1;
        return temp;
        }
      else if((*rootPtr)->right == NULL){
        temp = *rootPtr;
        (*rootPtr)->balanceFactor += 1;
        *rootPtr = (*rootPtr)->left;
        *heightFlag = 1;
        return temp;
        }
      else{
        temp = *rootPtr;
        *rootPtr = findNearest(&(*rootPtr)->right,heightFlag);
        if(*heightFlag == 1){
          temp->balanceFactor -= 1;
        }
        (*rootPtr)->balanceFactor = temp->balanceFactor;
        if(temp->right == NULL){
          (*rootPtr)->left = temp->left;
        }
        else{
          (*rootPtr)->left = temp->left;
          (*rootPtr)->right = temp->right;
        }

        *heightFlag = avlBalanceRightTree(rootPtr);

        if((*rootPtr)->balanceFactor != 0){
          *heightFlag = 0;
        }

      }
    }
    else{
      if(compare((void *)(intptr_t)delData,*rootPtr)== -1){
        temp = _avlRemove(&(*(rootPtr))->left,delData,compare,heightFlag);
        if(temp == NULL)
          return NULL;
        if(*heightFlag == 1){
          (*rootPtr)->balanceFactor+=1;
          *heightFlag = avlBalanceLeftTree(rootPtr);
        }
        else{
          *heightFlag = 0;
        }
        return temp;
      }
      else if(compare((void *)(intptr_t)delData,*rootPtr)== 1){
        temp = _avlRemove(&(*rootPtr)->right ,delData,compare,heightFlag);
        if(temp == NULL)
          return NULL;
        if(*heightFlag == 1){
          (*rootPtr)->balanceFactor  -=1;
          *heightFlag = avlBalanceRightTree(rootPtr);
        }
        else{
          *heightFlag = 0;
        }
      }
    }
    return temp;
  }
}

Node *findNearest(Node **rootPtr,int *heightFlag){
  Node *temp;
  if((*rootPtr) == NULL){
        *heightFlag = 1;
         return NULL;
    }
  if((*rootPtr)->left!=NULL){
    temp = findNearest(&(*rootPtr)->left,heightFlag);
    if(*heightFlag == 1){
      (*rootPtr)->balanceFactor += 1;
      *heightFlag = avlBalanceLeftTree(rootPtr);
      if((*rootPtr)->balanceFactor != 0)
        *heightFlag = 0;
    }
    if(temp->right != NULL){
      (*rootPtr)->left = temp->right;
      temp->right = NULL;
    }
    return temp;
  }
  else{
    temp = (*rootPtr);
    (*rootPtr) = NULL;
    *heightFlag = 1;
    return temp;
  }
}

int avlBalanceLeftTree(Node **rootPtr){
  Node *node = *rootPtr;

  if((*rootPtr)->balanceFactor  <= 1 ){
    if((*rootPtr)->balanceFactor == 0)
      return 1;
    else
      return 0;
  }

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

  if((*rootPtr)->balanceFactor >= -1){
    if((*rootPtr)->balanceFactor ==0)
      return 1;
    else
      return 0;
  }


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
