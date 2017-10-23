#include "unity.h"
#include "Node.h"
#include "NodeHelper.h"

void initNode(Node *node, Node *left, Node *right, int bf){
  node->left = left;
  node->right = right;
  node->balanceFactor = bf;
}
