#include "unity.h"
#include "AVL.h"
#include "Node.h"
#include "NodeHelper.h"
#include "NodeVerifier.h"
#include <stdio.h>

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
 *        add 50
 *    NULL-------> 50
 */
void test_avlAdd_given_empty_tree_add_node1_expect_node1_to_be_root(void){
  Node *root = NULL;
  initNode(&node50,&node40,&node55,100);

  avlAdd(&root, &node50);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_NODE(&node40,&node55,0,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
}

/**
 *   (add 55):
 *              50
 *               \
 *                55
 */
void test_avlAdd_given_root_node50_add_node55_expect_node55_to_be_placed_at_node50_right(void){
  Node *root = &node50;
  initNode(&node50,NULL,NULL,100);
  initNode(&node55,NULL,NULL,100);

  avlAdd(&root, &node55);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_NODE(NULL,&node55,0,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
}

/**
 *   (add 40):
 *              55
 *             /
 *            40
 */
void test_avlAdd_given_root_node55_add_node40_expect_node40_to_be_placed_at_node55_left(void){
  Node *root = &node55;
  initNode(&node55,NULL,NULL,100);
  initNode(&node40,NULL,NULL,100);

  avlAdd(&root, &node40);
  TEST_ASSERT_EQUAL_PTR(&node55,root);
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
}

/**
 *   (add 35):
 *              55
 *             /
 *            40
 *           /
 *          35
 */
void test_avlAdd_given_root_node55_and_node40_add_node35_expect_node35_to_be_placed_at_node40_left(void){
  Node *root = &node55;
  initNode(&node55,&node40,NULL,100);
  initNode(&node40,NULL,NULL,100);
  initNode(&node35,NULL,NULL,100);

  avlAdd(&root, &node35);
  TEST_ASSERT_EQUAL_PTR(&node55,root);
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(&node35,NULL,0,&node40);
}

/**
 *   (add 45):
 *              55
 *             /
 *            40
 *             \
 *             45
 */
void test_avlAdd_given_root_node55_and_node40_add_node45_expect_node45_to_be_placed_at_node40_right(void){
  Node *root = &node55;
  initNode(&node55,&node40,NULL,100);
  initNode(&node40,NULL,NULL,100);
  initNode(&node45,NULL,NULL,100);

  avlAdd(&root, &node45);
  TEST_ASSERT_EQUAL_PTR(&node55,root);
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(NULL,&node45,0,&node40);
}
