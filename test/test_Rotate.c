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
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node5);
  TEST_ASSERT_EQUAL_NODE(&node20,NULL,-2,&node30);
  TEST_ASSERT_EQUAL_NODE(&node5,&node30,0,&node10);
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
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node15);
  TEST_ASSERT_EQUAL_NODE(NULL,&node15,2,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node25);
  TEST_ASSERT_EQUAL_NODE(&node10,&node25,0,&node20);
}

/**
 *            10                     20
 *             \                    /  \
 *             20       ----->     10  25
 *              \
 *              25
 *
 */
void test_rotateLeft1(void){
  Node *root;
  initNode(&node25,NULL,NULL,0);
  initNode(&node20,NULL,&node25,1);
  initNode(&node10,NULL,&node20,2);

  root = rotateLeft(&node10);
  TEST_ASSERT_EQUAL_PTR(&node20,root);
  TEST_ASSERT_EQUAL_NODE(NULL,&node25,0,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node25);
  TEST_ASSERT_EQUAL_NODE(NULL,&node25,0,&node20);
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
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node15);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node25);
  TEST_ASSERT_EQUAL_NODE(NULL,&node15,1,&node10);
  TEST_ASSERT_EQUAL_NODE(&node25,NULL,0,&node30);
  TEST_ASSERT_EQUAL_NODE(&node10,&node30,0,&node20);
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
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node15);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node25);
  TEST_ASSERT_EQUAL_NODE(NULL,&node15,1,&node10);
  TEST_ASSERT_EQUAL_NODE(&node25,NULL,0,&node30);
  TEST_ASSERT_EQUAL_NODE(&node10,&node30,0,&node20);
}
