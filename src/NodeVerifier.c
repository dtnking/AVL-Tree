#include "NodeVerifier.h"
#include "Node.h"
#include "unity.h"
#include <stdarg.h>
#include <stdio.h>
#include <malloc.h>


char *createMessage(char *message, ...){
  va_list args;
  char *buffer;
  int length;

  va_start(args,message);

  length = vsnprintf(buffer, 0, message, args);
  buffer = malloc(length+1);
  vsnprintf(buffer, length+1, message, args);

  return buffer;
}

void testAssertEqualNode(Node *left, Node *right, int bf, Node *node,int lineNo){
  char *error;
  if(left != NULL){
    if(node->left == NULL){
      error = createMessage("Expected left node to be 0x%p, but was %p",  \
                            left,node->left);
    UNITY_TEST_FAIL(lineNo,error);
    }
  } else  {
    if(node->left != NULL){
      error = createMessage("Expected left node to be 0x%p, but was %p",  \
                            left,node->left);
    UNITY_TEST_FAIL(lineNo,error);
    }
  }

  if(right != NULL){
    if(node->right == NULL){
      error = createMessage("Expected right node to be 0x%p, but was %p",  \
                            right,node->right);
    UNITY_TEST_FAIL(lineNo,error);
    }
  } else {
    if(node->right != NULL){
      error = createMessage("Expected right node to be 0x%p, but was %p",  \
                            right,node->right);
    UNITY_TEST_FAIL(lineNo,error);
    }
  }
}
