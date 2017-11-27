#include "unity.h"
#include "Rotate.h"
#include <stdint.h>

Node node1, node5, node10, node15, node20, node25, node30, node35, node40;
Node node45, node50, node55;

void initNode(Node *node, Node *left, Node *right, int bf){
  node->left = left;
  node->right = right;
  node->balanceFactor = bf;
}

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
  initNode(&node30,&node10,NULL,-2);

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
 *            40(+2)                         50(0)
 *             \         Rotate Left         /   \
 *             50(+1)  -------------->    40(0)  55(0)
 *              \
 *              55(0)
 *
 */
void test_avlLeftBalanceTree_given_40_50_55_expect_balance_tree(void){
  Node *root = &node40;
  initNode(&node55,NULL,NULL,0);
  initNode(&node50,NULL,&node55,1);
  initNode(&node40,NULL,&node50,2);

  avlBalanceLeftTree(&root);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(&node40,&node55,0,&node50);
}

/**
 *            40(+2)                       50(-1)
 *             \         Rotate Left       /   \
 *             50(0)   -------------->   40(1)  55(0)
 *            /  \                         \
 *        45(0)   55(0)                   45(0)
 *
 */
void test_avlLeftBalanceTree_given_40_45_50_55_expect_balance_tree(void){
  Node *root = &node40;
  initNode(&node45,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node50,&node45,&node55,0);
  initNode(&node40,NULL,&node50,2);

  avlBalanceLeftTree(&root);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
  TEST_ASSERT_EQUAL_NODE(NULL,&node45,1,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(&node40,&node55,-1,&node50);
}

/**
 *            30(+2)                             45(0)
 *           /  \         Rotate Right          /    \
 *       20(0)  50(-1)      and Left         30(0)   50(+1)
 *             /   \      -------------->    /   \      \
*          45(-1)   55(0)                 20(0) 40(0)   55(0)
 *           /
 *        40(0)
 */
void test_avlLeftBalanceTree_given_30_20_50_45_55_40_expect_balance_tree(void){
  Node *root = &node30;
  initNode(&node30,&node20,&node50,2);
  initNode(&node20,NULL,NULL,0);
  initNode(&node50,&node45,&node55,-1);
  initNode(&node45,&node40,NULL,-1);
  initNode(&node55,NULL,NULL,0);
  initNode(&node40,NULL,NULL,0);

  avlBalanceLeftTree(&root);
  TEST_ASSERT_EQUAL_PTR(&node45,root);
  TEST_ASSERT_EQUAL_NODE(&node30,&node50,0,&node45);
  TEST_ASSERT_EQUAL_NODE(&node20,&node40,0,&node30);
  TEST_ASSERT_EQUAL_NODE(NULL,&node55,1,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
}

/**
 *            30(+2)                             45(0)
 *           /  \         Rotate Right         /      \
 *       20(0)  60(-1)     and Left         30(0)     60(0)
 *             /   \     --------------->   /   \      /  \
 *         45(0)   65(0)                 20(0) 40(0) 50(0) 65(0)
 *         /   \
 *      40(0) 50(0)
 */
void test_avlLeftBalanceTree_given_30_20_60_45_65_40_50_expect_balance_tree(void){
  Node *root = &node30;
  initNode(&node30,&node20,&node60,2);
  initNode(&node20,NULL,NULL,0);
  initNode(&node60,&node45,&node65,-1);
  initNode(&node45,&node40,&node50,0);
  initNode(&node65,NULL,NULL,0);
  initNode(&node40,NULL,NULL,0);
  initNode(&node50,NULL,NULL,0);

  avlBalanceLeftTree(&root);
  TEST_ASSERT_EQUAL_PTR(&node45,root);
  TEST_ASSERT_EQUAL_NODE(&node30,&node60,0,&node45);
  TEST_ASSERT_EQUAL_NODE(&node20,&node40,0,&node30);
  TEST_ASSERT_EQUAL_NODE(&node50,&node65,0,&node60);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node65);
}

/**
 *            30(+2)                             45(0)
 *           /  \         Rotate Right          /     \
 *       20(0)  60(-1)     and Left         30(-1)    60(0)
 *             /   \    ----------------->   /        /  \
 *          45(+1)  65(0)                  20(0)    50(0) 65(0)
 *           \
 *           50(0)
 */
void test_avlLeftBalanceTree_given_30_20_60_45_65_50_expect_balance_tree(void){
  Node *root = &node30;
  initNode(&node30,&node20,&node60,2);
  initNode(&node20,NULL,NULL,0);
  initNode(&node60,&node45,&node65,-1);
  initNode(&node45,NULL,&node50,1);
  initNode(&node65,NULL,NULL,0);
  initNode(&node50,NULL,NULL,0);

  avlBalanceLeftTree(&root);
  TEST_ASSERT_EQUAL_PTR(&node45,root);
  TEST_ASSERT_EQUAL_NODE(&node30,&node60,0,&node45);
  TEST_ASSERT_EQUAL_NODE(&node20,NULL,-1,&node30);
  TEST_ASSERT_EQUAL_NODE(&node50,&node65,0,&node60);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node65);
}

/**
 *            55(-2)                       50(0)
 *            /        Rotate Right       /    \
 *          50(-1)    -------------->   40(0)  55(0)
 *         /
 *       40(0)
 *
 */
void test_avlRightBalanceTree_given_40_50_55_expect_balance_tree(void){
  Node *root = &node55;
  initNode(&node55,&node50,NULL,-2);
  initNode(&node50,&node40,NULL,-1);
  initNode(&node40,NULL,NULL,0);

  avlBalanceRightTree(&root);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(&node40,&node55,0,&node50);
}

/**
 *            55(-2)                      45(1)
 *            /         Rotate Right     /   \
 *          45(0)       ----------->   40(0)  55(-1)
 *         /  \                        /
 *     40(0) 50(0)                   50(0)
 *
 */
void test_avlRightBalanceTree_given_40_45_50_55_expect_balance_tree(void){
  Node *root = &node55;
  initNode(&node55,&node45,NULL,-2);
  initNode(&node45,&node40,&node50,0);
  initNode(&node40,NULL,NULL,0);
  initNode(&node50,NULL,NULL,0);

  avlBalanceRightTree(&root);
  TEST_ASSERT_EQUAL_PTR(&node45,root);
  TEST_ASSERT_EQUAL_NODE(&node40,&node55,1,&node45);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(&node50,NULL,-1,&node55);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node50);
}

/**
 *              60(-2)                          50(0)
 *            /      \      Rotate Left        /     \
 *          45(+1)  65(0)    and Right      45(-1)  60(0)
 *         /  \            ------------->   /       /   \
 *     40(0)  50(+1)                      40(0)  55(0)  65(0)
 *              \
 *             55(0)
 */
void test_avlRightBalanceTree_given_60_45_65_40_50_55_expect_balance_tree(void){
  Node *root = &node60;
  initNode(&node60,&node45,&node65,-2);
  initNode(&node45,&node40,&node50,1);
  initNode(&node65,NULL,NULL,0);
  initNode(&node40,NULL,NULL,0);
  initNode(&node50,NULL,&node55,1);
  initNode(&node55,NULL,NULL,0);

  avlBalanceRightTree(&root);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_NODE(&node45,&node60,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,-1,&node45);
  TEST_ASSERT_EQUAL_NODE(&node55,&node65,0,&node60);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node65);
}
