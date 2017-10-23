#include "unity.h"
#include "Rotate.h"
#include "NodeVerifier.h"
#include "NodeHelper.h"
#include <stdint.h>

Node node1, node5, node10, node15, node20, node25, node30, node35, node40;
Node node45, node50, node55;


void setUp(void){
  node1.data = 1;
  node5.data = 5;
  node10.data = 10;
  node15.data = 15;
  node20.data = 20;
  node25.data = 25;
  node30.data = 30;
  node35.data = 35;
  node40.data = 40;
  node45.data = 45;
  node50.data = 50;
  node55.data = 55;
}

void tearDown(void){}

/**
 *              30                   10
 *             /                    / \
 *           10       ----->     5    30
 *          / \                      /
 *        5   20                   20
 *
 */
void test_rotateRight(void){
  Node *root;
  initNode(&node5,NULL,NULL,0);
  initNode(&node20,NULL,NULL,0);
  initNode(&node10,&node5,&node20,0);
  initNode(&node30,&node10,NULL,-2);

  root = rotateRight(&node30);
  TEST_ASSERT_EQUAL_PTR(&node10,root);
  TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
  TEST_ASSERT_EQUAL_PTR(&node20,node30.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.right);
  TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
  TEST_ASSERT_EQUAL_PTR(&node30,node10.right);
}


/**
 *            10                     20
 *             \                    /  \
 *             20       ----->     10  25
 *            /  \                   \
 *           15  25                  15
 *
 */
void test_rotateLeft(void){
  Node *root;
  initNode(&node15,NULL,NULL,0);
  initNode(&node25,NULL,NULL,0);
  initNode(&node20,&node15,&node25,0);
  initNode(&node10,NULL,&node20,2);

  root = rotateLeft(&node10);
  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_PTR(NULL,node15.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node15.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
  TEST_ASSERT_EQUAL_PTR(&node15,node10.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
  TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
  TEST_ASSERT_EQUAL_PTR(&node25,node20.right);
}


/**
 *              30                     30                 20
 *             /                      /                 /   \
 *           10       ----->        20     ----->     10    30
 *            \                    /  \                \    /
 *            20                 10   25               15  25
 *           /  \                 \
 *         15   25                15
 *
 */
void test_rotateLeftRight(void){
  Node *root;
  initNode(&node15,NULL,NULL,0);
  initNode(&node25,NULL,NULL,0);
  initNode(&node20,&node15,&node25,0);
  initNode(&node10,NULL,&node20,2);
  initNode(&node30,&node10,NULL,-3);

  root = rotateLeftRight(&node30);
  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_PTR(NULL,node15.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node15.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
  TEST_ASSERT_EQUAL_PTR(&node15,node10.right);
  TEST_ASSERT_EQUAL_PTR(&node25,node30.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.right);
  TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
  TEST_ASSERT_EQUAL_PTR(&node30,node20.right);
}


/**
 *           10                      10                    20
 *             \                      \                   /   \
 *             30       ----->        20     ----->     10    30
 *             /                     /  \                \    /
 *           20                    15   30               15  25
 *          /  \                        /
 *        15   25                      25
 *
 */
void test_rotateRightLeft(void){
  Node *root;
  initNode(&node15,NULL,NULL,0);
  initNode(&node25,NULL,NULL,0);
  initNode(&node20,&node15,&node25,0);
  initNode(&node30,&node20,NULL,-2);
  initNode(&node10,NULL,&node30,3);

  root = rotateRightLeft(&node10);
  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_PTR(NULL,node15.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node15.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
  TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
  TEST_ASSERT_EQUAL_PTR(&node15,node10.right);
  TEST_ASSERT_EQUAL_PTR(&node25,node30.left);
  TEST_ASSERT_EQUAL_PTR(NULL,node30.right);
  TEST_ASSERT_EQUAL_PTR(&node10,node20.left);
  TEST_ASSERT_EQUAL_PTR(&node30,node20.right);
}
