#include "unity.h"
#include "AVL.h"
#include "Node.h"
#include "NodeHelper.h"
#include "NodeVerifier.h"
#include <stdio.h>
#include "Rotate.h"

Node node1, node5, node10, node15, node20, node25, node30, node35, node40;
Node node45, node50, node55,node60,node65,node70,node75,node80,node85;

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
  node60.data = 60;
  node65.data = 65;
  node70.data = 70;
  node75.data = 75;
  node80.data = 80;
  node85.data = 85;
}

void tearDown(void){}

/**
 *       delete 50
 *    50 ----> NULL
 */
/*void test_avlDelete_given_50_delete_node50_expected_empty_tree(void){
  Node *root = &node50;
  initNode(&node50,NULL,NULL,0);

  avlDelete(&root, &node50);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_NODE(&node40,&node55,0,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
}*/


/**
 *        add same value
 *    50 ---add 50----> error
 */
void test_avlAdd_given_node50_add_node50_expected_error(void){
  Node *root = &node50;
  initNode(&node50,NULL,NULL,0);

  avlAdd(&root, &node50);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
}

/**
 *        add 50
 *    NULL-------> 50
 */
void test_avlAdd_given_empty_tree_add_node1_expected_node1_to_be_root(void){
  Node *root = NULL;
  initNode(&node50,NULL,NULL,0);

  avlAdd(&root, &node50);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node50);
}

/**
 *   (add 55):
 *              50
 *               \
 *                55
 */
void test_avlAdd_given_root_node50_add_node55_expected_balance_tree(void){
  Node *root = &node50;
  initNode(&node50,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);

  avlAdd(&root, &node55);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_NODE(NULL,&node55,1,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
}

/**
 *   (add 40):
 *              55
 *             /
 *            40
 */
void test_avlAdd_given_root_node55_add_node40_expected_balance_tree(void){
  Node *root = &node55;
  initNode(&node55,NULL,NULL,0);
  initNode(&node40,NULL,NULL,0);

  avlAdd(&root, &node40);
  TEST_ASSERT_EQUAL_PTR(&node55,root);
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,-1,&node55);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
}

/**
 *   (add 35):
 *              55               55                   40
 *             /      --->      /                    / \
 *            40              40       ---->       35  55
 *                           /
 *                         35
 */
void test_avlAdd_given_root_node55_and_node40_add_node35_expected_balance_tree(void){
  Node *root = &node55;
  initNode(&node55,&node40,NULL,-1);
  initNode(&node40,NULL,NULL,0);
  initNode(&node35,NULL,NULL,0);

  avlAdd(&root, &node35);
  TEST_ASSERT_EQUAL_PTR(&node40,root);
  TEST_ASSERT_EQUAL_NODE(&node35,&node55,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
}

/**
 *   (add 45):
 *              55                  55              45
 *             /      --->          /              /  \
 *            40                  40  ------>     40  55
 *                                 \
 *                                 45
 */
void test_avlAdd_given_root_node55_and_node40_add_node45_expected_balance_tree(void){
  Node *root = &node55;
  initNode(&node55,&node40,NULL,-1);
  initNode(&node40,NULL,NULL,0);
  initNode(&node45,NULL,NULL,0);

  avlAdd(&root, &node45);
  TEST_ASSERT_EQUAL_PTR(&node45,root);
  TEST_ASSERT_EQUAL_NODE(&node40,&node55,0,&node45);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
}

/**
 *   (add 60):
 *              55                  55                    60
 *               \     --->          \                   /  \
 *               65                  65  ------>       55   65
 *                                   /
 *                                 60
 */
void test_avlAdd_given_root_node55_and_node65_add_node60_expected_balance_tree(void){
  Node *root = &node55;
  initNode(&node55,NULL,&node65,1);
  initNode(&node65,NULL,NULL,0);
  initNode(&node60,NULL,NULL,0);

  avlAdd(&root, &node60);
  TEST_ASSERT_EQUAL_PTR(&node60,root);
  TEST_ASSERT_EQUAL_NODE(&node55,&node65,0,&node60);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node65);
}

/**
 *   (add 70):
 *              55                  55                    65
 *               \     --->          \                   /  \
 *               65                  65  ------>       55   70
 *                                    \
 *                                    70
 */
void test_avlAdd_given_root_node55_and_node65_add_node70_expected_balance_tree(void){
  Node *root = &node55;
  initNode(&node55,NULL,&node65,1);
  initNode(&node65,NULL,NULL,0);
  initNode(&node70,NULL,NULL,0);

  avlAdd(&root, &node70);
  TEST_ASSERT_EQUAL_PTR(&node65,root);
  TEST_ASSERT_EQUAL_NODE(&node55,&node70,0,&node65);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node70);
}

/**
 *   (add 45):
 *           55                   55
 *          /  \                 / \
 *         40  60    ---->     40  60
 *        /                   / \
 *       35                 35  45
 */
void test_avlAdd_given_root_node55_and_node40_node60_node35_add_node45_expected_balance_tree(void){
   Node *root = &node55;
   initNode(&node55,&node40,&node60,-1);
   initNode(&node40,&node35,NULL,-1);
   initNode(&node60,NULL,NULL,0);
   initNode(&node35,NULL,NULL,0);
   initNode(&node45,NULL,NULL,0);

   avlAdd(&root, &node45);
   TEST_ASSERT_EQUAL_PTR(&node55,root);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node60);
   TEST_ASSERT_EQUAL_NODE(&node35,&node45,0,&node40);
   TEST_ASSERT_EQUAL_NODE(&node40,&node60,-1,&node55);
 }

 /**
  *   (add 35):
  *           55                   55
  *          /  \                 / \
  *         40  60    ---->     40  60
  *          \                 / \
  *          45              35  45
  */
void test_avlAdd_given_root_node55_and_node40_node60_node45_add_node35_expected_balance_tree(void){
    Node *root = &node55;
    initNode(&node55,&node40,&node60,-1);
    initNode(&node40,NULL,&node45,1);
    initNode(&node60,NULL,NULL,0);
    initNode(&node35,NULL,NULL,0);
    initNode(&node45,NULL,NULL,0);

    avlAdd(&root, &node35);
    TEST_ASSERT_EQUAL_PTR(&node55,root);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node60);
    TEST_ASSERT_EQUAL_NODE(&node35,&node45,0,&node40);
    TEST_ASSERT_EQUAL_NODE(&node40,&node60,-1,&node55);
  }

/**
 *   (add 60):
 *           55                   55
 *          /  \                 /  \
 *         40  65    ---->     40    65
 *              \                   /  \
 *              75                 60  75
 */
void test_avlAdd_given_root_node55_and_node40_node60_node75_add_node60_expected_balance_tree(void){
   Node *root = &node55;
   initNode(&node55,&node40,&node65,1);
   initNode(&node40,NULL,NULL,0);
   initNode(&node65,NULL,&node75,1);
   initNode(&node75,NULL,NULL,0);
   initNode(&node60,NULL,NULL,0);

   avlAdd(&root, &node60);
   TEST_ASSERT_EQUAL_PTR(&node55,root);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node60);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);
   TEST_ASSERT_EQUAL_NODE(&node60,&node75,0,&node65);
   TEST_ASSERT_EQUAL_NODE(&node40,&node65,1,&node55);
   }

/**
 *   (add 75):
 *           55                   55
 *          /  \                 /  \
 *         40  65    ---->     40    65
 *             /                    /  \
 *           60                    60  75
 */
void test_avlAdd_given_root_node55_and_node40_node60_node65_add_node75_expected_balance_tree(void){
    Node *root = &node55;
    initNode(&node55,&node40,&node65,1);
    initNode(&node40,NULL,NULL,0);
    initNode(&node65,&node60,NULL,-1);
    initNode(&node75,NULL,NULL,0);
    initNode(&node60,NULL,NULL,0);

    avlAdd(&root, &node75);
    TEST_ASSERT_EQUAL_PTR(&node55,root);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node60);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);
    TEST_ASSERT_EQUAL_NODE(&node60,&node75,0,&node65);
    TEST_ASSERT_EQUAL_NODE(&node40,&node65,1,&node55);
}


/**
 *   (add 80):
 *           55                   55                            65
 *          /  \                 /  \                          /  \
 *         40  65    ---->     40   65         --->          55   75
 *            /  \                  / \                     / \    \
 *           60  75                60 75                  40  60   80
 *                                     \
  *                                    80
 */
void test_avlAdd_given_root_node55_and_node40_node65_node60_node75_add_node80_expected_balance_tree(void){
   Node *root = &node55;
   initNode(&node55,&node40,&node65,1);
   initNode(&node40,NULL,NULL,0);
   initNode(&node65,&node60,&node75,0);
   initNode(&node75,NULL,NULL,0);
   initNode(&node60,NULL,NULL,0);
   initNode(&node80,NULL,NULL,0);

   avlAdd(&root, &node80);
   TEST_ASSERT_EQUAL_PTR(&node65,root);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node60);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node80);
   TEST_ASSERT_EQUAL_NODE(&node55,&node75,0,&node65);
   TEST_ASSERT_EQUAL_NODE(&node40,&node60,0,&node55);
   TEST_ASSERT_EQUAL_NODE(NULL,&node80,1,&node75);
   }

/**
 *   (add 80):
 *           50                   50                            55
 *          /  \                 /  \                          /  \
 *         40  65    ---->     40   65         --->          50   65
 *            /  \                  / \                     /     / \
 *           55  75                55  75                  40    60 75
 *                                /
 *                              60
 */
void test_avlAdd_given_root_node50_and_node40_node65_node55_node75_add_node60_expected_balance_tree(void){
  Node *root = &node50;
  initNode(&node50,&node40,&node65,1);
  initNode(&node40,NULL,NULL,0);
  initNode(&node65,&node55,&node75,0);
  initNode(&node75,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node80,NULL,NULL,0);
  initNode(&node60,NULL,NULL,0);

  avlAdd(&root, &node60);
  TEST_ASSERT_EQUAL_PTR(&node55,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node60);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,-1,&node50);
  TEST_ASSERT_EQUAL_NODE(&node60,&node75,0,&node65);
  TEST_ASSERT_EQUAL_NODE(&node50,&node65,0,&node55);
  }

/**
 *   (add 85):
 *           55                   55                            55
 *          /  \                 /  \                          /  \
 *         40  65    ---->     40   65         --->          40   65
 *        /   /  \            /     / \                     /     / \
 *      30   60  75         30     60 75                  30    60  80
 *                \                    \                            / \
 *                80                   80                         75  85
 *                                      \
 *                                      85
 */
void test_avlAdd_given_root_node55_and_node40_node65_node30_node60_node75_node80_add_node85_expected_balance_tree(void){
   Node *root = &node55;
   initNode(&node55,&node40,&node65,1);
   initNode(&node40,&node30,NULL,-1);
   initNode(&node65,&node60,&node75,1);
   initNode(&node75,NULL,&node80,1);
   initNode(&node30,NULL,NULL,0);
   initNode(&node80,NULL,NULL,0);
   initNode(&node60,NULL,NULL,0);
   initNode(&node85,NULL,NULL,0);

   avlAdd(&root, &node85);
   TEST_ASSERT_EQUAL_PTR(&node55,root);
   TEST_ASSERT_EQUAL_NODE(&node30,NULL,-1,&node40);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node30);
   TEST_ASSERT_EQUAL_NODE(&node60,&node80,1,&node65);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node60);
   TEST_ASSERT_EQUAL_NODE(&node75,&node85,0,&node80);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node85);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);

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

/**
 *              70(-2)                              60(0)
 *            /      \         Rotate Right       /      \
 *          50(+1)  75(0)       and Left       50(0)     70(0)
 *         /  \              -------------->   /  \       /   \
 *     40(0)  60(0)                         40(0) 55(0) 65(0) 75(0)
 *            /   \
 *         55(0) 65(0)
 */
void test_avlRightBalanceTree_given_70_50_75_40_60_55_65_expect_balance_tree(void){
  Node *root = &node70;
  initNode(&node70,&node50,&node75,-2);
  initNode(&node50,&node40,&node60,1);
  initNode(&node75,NULL,NULL,0);
  initNode(&node40,NULL,NULL,0);
  initNode(&node60,&node55,&node65,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node65,NULL,NULL,0);

  avlBalanceRightTree(&root);
  TEST_ASSERT_EQUAL_PTR(&node60,root);
  TEST_ASSERT_EQUAL_NODE(&node50,&node70,0,&node60);
  TEST_ASSERT_EQUAL_NODE(&node40,&node55,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node65,&node75,0,&node70);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node65);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);
}

/**
 *              70(-2)                              60(0)
 *            /      \       Rotate Right         /     \
 *          50(+1)  75(0)     and Left         50(0)    70(+1)
 *         /  \              ---------->       /  \        \
 *     40(0)  60(-1)                        40(0) 55(0)    75(0)
 *            /
 *          55(0)
 */
void test_avlRightBalanceTree_given_70_50_75_40_60_55_expect_balance_tree(void){
  Node *root = &node70;
  initNode(&node70,&node50,&node75,-2);
  initNode(&node50,&node40,&node60,1);
  initNode(&node40,NULL,NULL,0);
  initNode(&node60,&node55,NULL,-1);
  initNode(&node55,NULL,NULL,0);
  initNode(&node75,NULL,NULL,0);

  avlBalanceRightTree(&root);
  TEST_ASSERT_EQUAL_PTR(&node60,root);
  TEST_ASSERT_EQUAL_NODE(&node50,&node70,0,&node60);
  TEST_ASSERT_EQUAL_NODE(&node40,&node55,0,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,&node75,1,&node70);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);
}

/* Remove node 40
 *          50(-1)           50(0)
 *         /         --->
 *       40(0)
 */
void test_avlDelete_given_node50_and_node40_delete_node40_expect_left_node50(void){
  Node *root= &node50;
  initNode(&node50,&node40,NULL,-1);
  initNode(&node40,NULL,NULL,0);

  avlDelete(&root,&node40);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node50);
}

/* Remove node 55
 *          50(0)              50(-1)
 *         /   \      --->    /
 *     40(0)  55(0)        40(0)
 */
void test_avlDelete_given_node50_and_node40_node55_delete_node55_expect_left_node50_node_40(void){
  Node *root= &node50;
  initNode(&node50,&node40,&node55,0);
  initNode(&node40,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);

  avlDelete(&root,&node55);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_NODE(&node40,NULL,-1,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
}

/* Remove node 55
 *          50(-1)              50(-2)                    40(0)
 *         /   \      --->    /             ---->        /   \
 *     40(-1)  55(0)        40(-1)                    35(0) 50(0)
 *      /                   /
 *   35(0)                35(0)
 */
void test_avlDelete_given_node50_and_node40_node35_node55_delete_node55_expect_balance_tree(void){
  Node *root= &node50;
  initNode(&node50,&node40,&node55,-1);
  initNode(&node40,&node35,NULL,-1);
  initNode(&node35,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);

  avlDelete(&root,&node55);
  TEST_ASSERT_EQUAL_PTR(&node40,root);
  TEST_ASSERT_EQUAL_NODE(&node35,&node50,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node50);
}

/* Remove node 55
 *          50(-1)              50(-2)                    40(1)
 *         /   \      --->    /             ---->        /    \
 *     40(0)  55(0)        40(-1)                    35(0)   50(-1)
 *     /  \               /   \                              /
 * 35(0) 45(0)         35(0) 45(0)                         45(0)
 */
void test_avlDelete_given_node50_and_node40_node35_node45_node55_delete_node55_expect_balance_tree(void){
  Node *root= &node50;
  initNode(&node50,&node40,&node55,-1);
  initNode(&node40,&node35,&node45,0);
  initNode(&node35,NULL,NULL,0);
  initNode(&node45,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);

  avlDelete(&root,&node55);
  TEST_ASSERT_EQUAL_PTR(&node40,root);
  TEST_ASSERT_EQUAL_NODE(&node35,&node50,1,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
  TEST_ASSERT_EQUAL_NODE(&node45,NULL,-1,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
}

/* Remove node 40
 *          50(-1)              50(-1)
 *         /   \      --->    /     \
 *     40(0)  55(0)        45(-1)   55(0)
 *     /  \                /
 * 35(0) 45(0)           35(0)
 */
 void test_avlDelete_given_node50_and_node40_node35_node45_node55_delete_node40_expect_balance_tree(void){
   Node *root= &node50;
   initNode(&node50,&node40,&node55,-1);
   initNode(&node40,&node35,&node45,0);
   initNode(&node35,NULL,NULL,0);
   initNode(&node45,NULL,NULL,0);
   initNode(&node55,NULL,NULL,0);

   avlDelete(&root,&node40);
   TEST_ASSERT_EQUAL_PTR(&node50,root);
   TEST_ASSERT_EQUAL_NODE(&node45,&node55,-1,&node50);
   TEST_ASSERT_EQUAL_NODE(&node35,NULL,-1,&node45);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
}
