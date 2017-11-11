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
 *      +2     -1      +1   |   RL   | -1       0       0   |
 *      -2     -1       x   |   R    |  0       0       x   |
 *      -2      0       x   |   R    | -1       1       x   |
 *      -2     +1      +1   |   LR   |  0      -1       0   |
 *      -2     +1       0   |   LR   |  0       0       0   |
 *      -2     +1      -1   |   LR   |  1       0       0   |
 *  -----------------------------------------------------------------
 */
   int heightChanged;
int avlAdd(Node **rootPtr, Node *nodeToAdd){

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

      return avlBalanceRightTree(&(*rootPtr));
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

      return avlBalanceLeftTree(&(*rootPtr));
    }
  }
}

/*Node *avlDelete(Node **rootPtr, Node *nodeToDelete){
  if (*rootPtr== NULL)
    return *rootPtr;
  else{
    if((*rootPtr)->data > nodeToDelete->data){
      (*rootPtr)->left = avlDelete(&(*rootPtr)->left,nodeToDelete);
    }else if((*rootPtr)->data < nodeToDelete->data){
      (*rootPtr)->right = avlDelete(&(*rootPtr)->right,nodeToDelete)
    }else {
      if()
    }

  }
  return *rootPtr;
}*/
int avlBalanceLeftTree(Node **rootPtr){
  Node *node = *rootPtr;

  if((*rootPtr)->balanceFactor  <= 1)
    return 1;

  if(node->right->balanceFactor == 1 ){
    node->balanceFactor = 0;
    node->right->balanceFactor = 0;
    *rootPtr = rotateLeft(*rootPtr);
    }
  else if(node->right->balanceFactor == 0){
    node->balanceFactor = 1;
    node->right->balanceFactor = -1;
    *rootPtr = rotateLeft(*rootPtr);
    }
  else if(node->right->balanceFactor == -1){
    if(node->right->left->balanceFactor == -1){
      node->balanceFactor = 0;
      node->right->balanceFactor = 1;
      node->right->left->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
    else if(node->right->left->balanceFactor == 0){
      node->balanceFactor = 0;
      node->right->balanceFactor = 0;
      node->right->left->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
    else if(node->right->left->balanceFactor == 1){
      node->balanceFactor = -1;
      node->right->balanceFactor = 0;
      node->right->left->balanceFactor = 0;
      *rootPtr = rotateRightLeft(*rootPtr);
      }
    }

  return 0;
}

int avlBalanceRightTree(Node **rootPtr){
  Node *node = *rootPtr;



  if((*rootPtr)->balanceFactor >= -1)
    return 1;


  if(node->left->balanceFactor == -1 ){
    node->balanceFactor = 0;
    node->left->balanceFactor = 0;
    *rootPtr = rotateRight(*rootPtr);
    }
  else if(node->left->balanceFactor == 0){
    node->balanceFactor = -1;
    node->left->balanceFactor = 1;
    *rootPtr = rotateRight(*rootPtr);
    }
  else if(node->left->balanceFactor ==1){
    if(node->left->right->balanceFactor == 1){
      node->balanceFactor = 0;
      node->left->balanceFactor = -1;
      node->left->right->balanceFactor = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      }
    else if(node->left->right->balanceFactor == 0){
      node->balanceFactor = 0;
      node->left->balanceFactor = 0;
      node->left->right->balanceFactor = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      }
    else if(node->left->right->balanceFactor == -1){
      node->balanceFactor = 1;
      node->left->balanceFactor = 0;
      node->left->right->balanceFactor = 0;
      *rootPtr = rotateLeftRight(*rootPtr);
      }

  }
  return 0;
}
