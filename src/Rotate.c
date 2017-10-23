#include "Rotate.h"

Node *rotateRight(Node *node){
  Node *temp = node->left;
  node->left = temp->right;
  temp->right = node;
  return temp;
}

Node *rotateLeft(Node *node){
  Node *temp = node->right;
  node->right = temp->left;
  temp->left = node;
  return temp;
}

Node *rotateLeftRight(Node *node){
  node->left = rotateLeft(node->left);
  Node *temp = rotateRight(node);
  return temp;
}

Node *rotateRightLeft(Node *node){
  node->right = rotateRight(node->right);
  Node *temp = rotateLeft(node);
  return temp;
}
