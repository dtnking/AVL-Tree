#include "AVL.h"

/** ------------------------------------------------------------------
 *           before         |        |        after         |
 *                    grand |        |                grand | height
 *     root   child   child | action | root   child   child | change
 *  ------------------------------------------------------------------
 *      +2     +1       x   |   L    |  0       0       x   |
 *      +2      0       x   |   L    |  1      -1       x   |
 *      +2     -1      -1   |   RL   |  0       1       0   |
 *      +2     -1       0   |   RL   |  0       0       0   |
 *      +2     -1      +1   |   RL   | -1      -1       0   |
 *      -2     -1       x   |   R    |  0       0       x   |
 *      -2      0       x   |   R    | -1       1       x   |
 *      -2     +1      +1   |   LR   |  0      -1       0   |
 *      -2     +1       0   |   LR   |  0       0       0   |
 *      -2     +1      -1   |   LR   |  1       0       0   |
 *  -----------------------------------------------------------------
 */
Node *avlAdd(Node **rootPtr, Node *nodeToAdd){
  if(*rootPtr == NULL){
    *rootPtr = nodeToAdd;
    return *rootPtr;
  } else {
    if ((*rootPtr)->data > nodeToAdd->data){
        (*rootPtr)->left = avlAdd(&(*rootPtr)->left,nodeToAdd);
        (*rootPtr)->balanceFactor -= 1;
      }
    else{
        (*rootPtr)->right = avlAdd(&(*rootPtr)->right,nodeToAdd);
        (*rootPtr)->balanceFactor += 1;
      }
  }
  if((*rootPtr)->balanceFactor >= 2){
    avlBalanceLeftTree(&(*rootPtr));
  }
  else if((*rootPtr)->balanceFactor <= -2){
    avlBalanceRightTree(&(*rootPtr));
  }
  return *rootPtr;
}

int avlBalanceLeftTree(Node **rootPtr){
  Node *node = *rootPtr;
  Node *child = node->right;
  Node *grandChild = node->right->left;

  if(child->balanceFactor > 0 ){
    node->balanceFactor = 0;
    child->balanceFactor = 0;
    *rootPtr = rotateLeft(*rootPtr);
    }
  else if(child->balanceFactor == 0){
    node->balanceFactor = 1;
    child->balanceFactor = -1;
    *rootPtr = rotateLeft(*rootPtr);
    }
  else if(child->balanceFactor == -1){
    if(grandChild->balanceFactor == -1){
      node->balanceFactor = 0;
      child->balanceFactor = 1;
      grandChild->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
    else if(grandChild->balanceFactor == 0){
      node->balanceFactor = 0;
      child->balanceFactor = 0;
      grandChild->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
    else if(grandChild->balanceFactor == 1){
      node->balanceFactor = -1;
      child->balanceFactor = 0;
      grandChild->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
  }
  return 0;
}

int avlBalanceRightTree(Node **rootPtr){
  Node *node = *rootPtr;
  Node *child = node->left;
  Node *grandChild = node->left->right;

  if(child->balanceFactor < 0 ){
    node->balanceFactor = 0;
    child->balanceFactor = 0;
    *rootPtr = rotateRight(*rootPtr);
    }
  else if(child->balanceFactor == 0){
    node->balanceFactor = -1;
    child->balanceFactor = 1;
    *rootPtr = rotateRight(*rootPtr);
    }
  else if(child->balanceFactor == 1){
    if(grandChild->balanceFactor == 1){
      node->balanceFactor = 0;
      child->balanceFactor = -1;
      grandChild->balanceFactor = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      }
    else if(grandChild->balanceFactor == 0){
      node->balanceFactor = 0;
      child->balanceFactor = 0;
      grandChild->balanceFactor = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      }
    else if(grandChild->balanceFactor == -1){
      node->balanceFactor = 1;
      child->balanceFactor = 0;
      grandChild->balanceFactor = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      }
  }
  return 0;
}
