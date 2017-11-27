#include "unity.h"
#include "AVL.h"
#include "Node.h"
#include "NodeHelper.h"
#include "NodeVerifier.h"
#include "AvlInteger.h"
#include <stdint.h>
#include <stdio.h>
#include "Rotate.h"

Node node1, node5, node10, node15, node20, node25, node30, node35, node40;
Node node45, node50, node55,node60,node65,node70,node75,node80,node85,node90,node95,node100,node105,node110,node115,node120,node125,node130,node135,node140,node145,node150,node155,node160,node165,node170,node175,node180,node185,node190,node195,node200,node205,node210,node215,node220,node225,node230;

#define initIntegerNode(n,l,r,bf)  initNode((Node *)n,(Node *)l,(Node *)r,bf)

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
  node90.data = 90;
  node95.data = 95;
  node100.data = 100;
  node105.data = 105;
  node110.data = 110;
  node115.data = 115;
  node120.data = 120;
  node125.data = 125;
  node130.data = 130;
  node135.data = 135;
  node140.data = 140;
  node145.data = 145;
  node150.data = 150;
  node155.data = 155;
  node160.data = 160;
  node165.data = 165;
  node170.data = 170;
  node175.data = 175;
  node180.data = 180;
  node185.data = 185;
  node190.data = 190;
  node195.data = 195;
  node200.data = 200;
  node205.data = 205;
  node210.data = 210;
  node215.data = 215;
  node220.data = 220;
  node225.data = 225;
  node230.data = 230;
}

void tearDown(void){}

/**
 *        add same value
 *    50 ---add 50----> error
 */
void test_avlAdd_given_IntegerNode50_add_IntegerNode50_expected_error(void){
  Node *root = &node50;
  initIntegerNode(&node50,NULL,NULL,0);
  avlAddInteger(&root, &node50);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
}


/**
 *   (add 55):
 *              50
 *               \
 *                55
 */
void test_avlAdd_given_root_node50_add_node55_expected_balance_tree(void){
  Node *root = &node50;
  initIntegerNode(&node50,NULL,NULL,0);
  initIntegerNode(&node55,NULL,NULL,0);

  avlAddInteger(&root, &node55);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_NODE(NULL,&node55,1,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
}
/**
 *        add same value
 *    50 ---add 50----> error
 */
void test_avlAdd_given_IntegerNode50_add_IntegerNode50_expected_error(void){
  Node *root = &node50;
  initIntegerNode(&node50,NULL,NULL,0);
  int cmp;
  avlAdd(&root, &node50,cmp);
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
  initIntegerNode(&node50,NULL,NULL,0);

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
  initIntegerNode(&node50,NULL,NULL,0);
  initIntegerNode(&node55,NULL,NULL,0);

  avlAdd(&root, &node55);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_NODE(NULL,&node55,1,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
}

/**
 *   (add same value 55):
 *              55
 */
void test_avlAdd_given_root_node55_add_node55_expected_Error(void){
  Node *root = &node55;
  initIntegerNode(&node55,NULL,NULL,0);

  avlAdd(&root, &node55);
  TEST_ASSERT_EQUAL_PTR(&node55,root);

}

/**
 *   (add 40):
 *              55
 *             /
 *            40
 */
void test_avlAdd_given_root_node55_add_node40_expected_balance_tree(void){
  Node *root = &node55;
  initIntegerNode(&node55,NULL,NULL,0);
  initIntegerNode(&node40,NULL,NULL,0);

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
  initIntegerNode(&node55,&node40,NULL,-1);
  initIntegerNode(&node40,NULL,NULL,0);
  initIntegerNode(&node35,NULL,NULL,0);

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
  initIntegerNode(&node55,&node40,NULL,-1);
  initIntegerNode(&node40,NULL,NULL,0);
  initIntegerNode(&node45,NULL,NULL,0);

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
  initIntegerNode(&node55,NULL,&node65,1);
  initIntegerNode(&node65,NULL,NULL,0);
  initIntegerNode(&node60,NULL,NULL,0);

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
  initIntegerNode(&node55,NULL,&node65,1);
  initIntegerNode(&node65,NULL,NULL,0);
  initIntegerNode(&node70,NULL,NULL,0);

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
   initIntegerNode(&node55,&node40,&node60,-1);
   initIntegerNode(&node40,&node35,NULL,-1);
   initIntegerNode(&node60,NULL,NULL,0);
   initIntegerNode(&node35,NULL,NULL,0);
   initIntegerNode(&node45,NULL,NULL,0);

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
    initIntegerNode(&node55,&node40,&node60,-1);
    initIntegerNode(&node40,NULL,&node45,1);
    initIntegerNode(&node60,NULL,NULL,0);
    initIntegerNode(&node35,NULL,NULL,0);
    initIntegerNode(&node45,NULL,NULL,0);

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
   initIntegerNode(&node55,&node40,&node65,1);
   initIntegerNode(&node40,NULL,NULL,0);
   initIntegerNode(&node65,NULL,&node75,1);
   initIntegerNode(&node75,NULL,NULL,0);
   initIntegerNode(&node60,NULL,NULL,0);

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
    initIntegerNode(&node55,&node40,&node65,1);
    initIntegerNode(&node40,NULL,NULL,0);
    initIntegerNode(&node65,&node60,NULL,-1);
    initIntegerNode(&node75,NULL,NULL,0);
    initIntegerNode(&node60,NULL,NULL,0);

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
   initIntegerNode(&node55,&node40,&node65,1);
   initIntegerNode(&node40,NULL,NULL,0);
   initIntegerNode(&node65,&node60,&node75,0);
   initIntegerNode(&node75,NULL,NULL,0);
   initIntegerNode(&node60,NULL,NULL,0);
   initIntegerNode(&node80,NULL,NULL,0);

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
  initIntegerNode(&node50,&node40,&node65,1);
  initIntegerNode(&node40,NULL,NULL,0);
  initIntegerNode(&node65,&node55,&node75,0);
  initIntegerNode(&node75,NULL,NULL,0);
  initIntegerNode(&node55,NULL,NULL,0);
  initIntegerNode(&node80,NULL,NULL,0);
  initIntegerNode(&node60,NULL,NULL,0);

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
 *           55(1)                   55(2)                         55(1)
 *          /  \                    /  \                          /    \
 *     40(-1)  65(1)    ---->  40(-1)  65(2)         --->     40(-1)   65(1)
 *      /     /    \            /      /   \                   /       /  \
 *   30(0)  60(0)  75(1)     30(0)  60(0)  75(2)             30(0)  60(0) 80(0)
 *                   \                       \                           /  \
 *                   80(0)                    80(1)                  75(0)  85(0)
 *                                             \
 *                                              85(0)
 */
void test_avlAdd_given_root_node55_and_node40_node65_node30_node60_node75_node80_add_node85_expected_balance_tree(void){
   Node *root = &node55;
   initIntegerNode(&node55,&node40,&node65,1);
   initIntegerNode(&node40,&node30,NULL,-1);
   initIntegerNode(&node65,&node60,&node75,1);
   initIntegerNode(&node75,NULL,&node80,1);
   initIntegerNode(&node30,NULL,NULL,0);
   initIntegerNode(&node80,NULL,NULL,0);
   initIntegerNode(&node60,NULL,NULL,0);
   initIntegerNode(&node85,NULL,NULL,0);

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

/* Remove node 40
 *          50(-1)           50(0)
 *         /         --->
 *       40(0)
 */
void test_avlRemove_given_node50_and_node40_delete_node40_expect_left_node50(void){
  Node *root= &node50;
  initIntegerNode(&node50,&node40,NULL,-1);
  initIntegerNode(&node40,NULL,NULL,0);

  avlRemove(&root,40);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node50);
}

/* Remove node 55
 *          50(0)              50(-1)
 *         /   \      --->    /
 *     40(0)  55(0)        40(0)
 */
void test_avlRemove_given_node50_and_node40_node55_delete_node55_expect_left_node50_node_40(void){
  Node *root= &node50;
  initIntegerNode(&node50,&node40,&node55,0);
  initIntegerNode(&node40,NULL,NULL,0);
  initIntegerNode(&node55,NULL,NULL,0);

  avlRemove(&root,55);
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
void test_avlRemove_given_node50_and_node40_node35_node55_delete_node55_expect_balance_tree(void){
  Node *root= &node50;
  initIntegerNode(&node50,&node40,&node55,-1);
  initIntegerNode(&node40,&node35,NULL,-1);
  initIntegerNode(&node35,NULL,NULL,0);
  initIntegerNode(&node55,NULL,NULL,0);

  avlRemove(&root,55);
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
void test_avlRemove_given_node50_and_node40_node35_node45_node55_delete_node55_expect_balance_tree(void){
  Node *root= &node50;
  initIntegerNode(&node50,&node40,&node55,-1);
  initIntegerNode(&node40,&node35,&node45,0);
  initIntegerNode(&node35,NULL,NULL,0);
  initIntegerNode(&node45,NULL,NULL,0);
  initIntegerNode(&node55,NULL,NULL,0);

  avlRemove(&root,55);
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
 void test_avlRemove_given_node50_and_node40_node35_node45_node55_delete_node40_expect_balance_tree(void){
   Node *root= &node50;
   initIntegerNode(&node50,&node40,&node55,-1);
   initIntegerNode(&node40,&node35,&node45,0);
   initIntegerNode(&node35,NULL,NULL,0);
   initIntegerNode(&node45,NULL,NULL,0);
   initIntegerNode(&node55,NULL,NULL,0);

   avlRemove(&root,40);
   TEST_ASSERT_EQUAL_PTR(&node50,root);
   TEST_ASSERT_EQUAL_NODE(&node45,&node55,-1,&node50);
   TEST_ASSERT_EQUAL_NODE(&node35,NULL,-1,&node45);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
}


/* Remove node 50
 *          50(1)                  55(0)
 *         /   \      --->        /    \
 *    40(-1)  70(-1)           40(-1)   70(0)
 *     /     /   \            /        /  \
 * 35(0)   55(1) 75(0)     35(0)    60(0) 75(0)
 *           \
 *          60(0)
 */
 void test_avlRemove_given_Node_above_delete_node50_expect_balance_tree(void){
   Node *root= &node50;
   initIntegerNode(&node50,&node40,&node70,1);
   initIntegerNode(&node40,&node35,NULL,-1);
   initIntegerNode(&node70,&node55,&node75,-1);
   initIntegerNode(&node35,NULL,NULL,0);
   initIntegerNode(&node55,NULL,&node60,1);
   initIntegerNode(&node75,NULL,NULL,0);
   initIntegerNode(&node60,NULL,NULL,0);

   avlRemove(&root,50);
   TEST_ASSERT_EQUAL_PTR(&node55,root);
   TEST_ASSERT_EQUAL_NODE(&node40,&node70,0,&node55);
   TEST_ASSERT_EQUAL_NODE(&node35,NULL,-1,&node40);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
   TEST_ASSERT_EQUAL_NODE(&node60,&node75,0,&node70);
   TEST_ASSERT_EQUAL_NODE(&node60,&node75,0,&node70);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node60);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);
}

/* Remove node 50
 *          50(1)                  70(0)
 *         /   \      --->        /    \
 *      40(0)  70(1)            40(0)   75(0)
 *                \
 *               75(0)
 */
 void test_avlRemove_given_Node_above_delete_node50_expect_balance_tree1(void){
   Node *root= &node50;
   initIntegerNode(&node50,&node40,&node70,1);
   initIntegerNode(&node40,NULL,NULL,0);
   initIntegerNode(&node70,NULL,&node75,1);
   initIntegerNode(&node75,NULL,NULL,0);

   avlRemove(&root,50);
   TEST_ASSERT_EQUAL_PTR(&node70,root);
   TEST_ASSERT_EQUAL_NODE(&node40,&node75,0,&node70);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);
}

/* Remove node 50
 *          50(1)                  65(1)
 *         /   \      --->        /    \
 *      40(0)  70(0)           40(0)   70(1)
 *             /  \                      \
 *          65(0) 75(0)                 75(0)
 */
 void test_avlRemove_given_Node_above_delete_node50_expect_balance_tree2(void){
   Node *root= &node50;
   initIntegerNode(&node50,&node40,&node70,1);
   initIntegerNode(&node40,NULL,NULL,0);
   initIntegerNode(&node70,&node65,&node75,0);
   initIntegerNode(&node65,NULL,NULL,0);
   initIntegerNode(&node75,NULL,NULL,0);

   avlRemove(&root,50);
   TEST_ASSERT_EQUAL_PTR(&node65,root);
   TEST_ASSERT_EQUAL_NODE(&node40,&node70,1,&node65);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
   TEST_ASSERT_EQUAL_NODE(NULL,&node75,1,&node70);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);
}

/* Remove node 35
 *          50(1)                  50(1)                                      70(0)
 *         /   \      --->        /    \              ----->                 /   \
 *     40(-1) 70(1)           40(0)   70(1)                               50(0)   75(1)
 *       /     /  \                    /  \                              /   \     \
 *    35(0) 65(0) 75(1)             65(0) 75(1)                       40(0) 65(0)  80(0)
 *                  \                       \
 *                 80(0)                   80(0)
 */
 void test_avlRemove_given_Node_above_delete_node35_expect_balance_tree(void){
   Node *root= &node50;
   initIntegerNode(&node50,&node40,&node70,1);
   initIntegerNode(&node40,&node35,NULL,-1);
   initIntegerNode(&node70,&node65,&node75,1);
   initIntegerNode(&node35,NULL,NULL,0);
   initIntegerNode(&node65,NULL,NULL,0);
   initIntegerNode(&node75,NULL,&node80,1);
   initIntegerNode(&node80,NULL,NULL,0);

   avlRemove(&root,35);
   TEST_ASSERT_EQUAL_PTR(&node70,root);
   TEST_ASSERT_EQUAL_NODE(&node50,&node75,0,&node70);
   TEST_ASSERT_EQUAL_NODE(&node40,&node65,0,&node50);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node65);
   TEST_ASSERT_EQUAL_NODE(NULL,&node80,1,&node75);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node80);
}


/* Remove node 50
 *          50(-1)                  40(0)
 *         /       --->
 *     40(0)
 *
 */
 void test_avlRemove_given_Node_above_delete_node50_expect_balance_tree4(void){
   Node *root= &node50;
   initIntegerNode(&node50,&node40,NULL,-1);
   initIntegerNode(&node40,NULL,NULL,0);

   avlRemove(&root,50);
   TEST_ASSERT_EQUAL_PTR(&node40,root);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
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
  initIntegerNode(&node70,&node50,&node75,-2);
  initIntegerNode(&node50,&node40,&node60,1);
  initIntegerNode(&node75,NULL,NULL,0);
  initIntegerNode(&node40,NULL,NULL,0);
  initIntegerNode(&node60,&node55,&node65,0);
  initIntegerNode(&node55,NULL,NULL,0);
  initIntegerNode(&node65,NULL,NULL,0);

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
  initIntegerNode(&node70,&node50,&node75,-2);
  initIntegerNode(&node50,&node40,&node60,1);
  initIntegerNode(&node40,NULL,NULL,0);
  initIntegerNode(&node60,&node55,NULL,-1);
  initIntegerNode(&node55,NULL,NULL,0);
  initIntegerNode(&node75,NULL,NULL,0);

  avlBalanceRightTree(&root);
  TEST_ASSERT_EQUAL_PTR(&node60,root);
  TEST_ASSERT_EQUAL_NODE(&node50,&node70,0,&node60);
  TEST_ASSERT_EQUAL_NODE(&node40,&node55,0,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,&node75,1,&node70);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);
}

/**
---------------------------------------remove 60----------------------------------------
*                  60                           60 (0)
*                /    \       remove 40        /   \
*               40      90    ---------->     30    90(1)
*              /  \    /   \                 / \   /  \
*            20   50  75   100             20  50  75  100
*           / \    \   \                   /   / \   \
*         10   30   55  80               10   35  55  80
*               \
*               35
*
**/
void test_remove_given_Avl_tree_remove_60_test2(void){

  initIntegerNode(&node60,&node40,&node90,-1);
  initIntegerNode(&node40,&node20,&node50,-1);
  initIntegerNode(&node90,&node75,&node100,-1);
  initIntegerNode(&node20,&node10,&node30,1);
  initIntegerNode(&node50,NULL,&node55,1);
  initIntegerNode(&node75,NULL,&node80,1);
  initIntegerNode(&node100,NULL,NULL,0);
  initIntegerNode(&node30,NULL,&node35,1);
  initIntegerNode(&node10,NULL,NULL,0);
  initIntegerNode(&node55,NULL,NULL,0);
  initIntegerNode(&node80,NULL,NULL,0);
  initIntegerNode(&node100,NULL,NULL,0);


  Node *root = &node60;
  avlRemove(&root,40);
  TEST_ASSERT_EQUAL_PTR(&node60,root);
  TEST_ASSERT_EQUAL_NODE(&node30,&node90,0,&node60);
  TEST_ASSERT_EQUAL_NODE(&node20,&node50,0,&node30);
  TEST_ASSERT_EQUAL_NODE(&node75,&node100,-1,&node90);
  TEST_ASSERT_EQUAL_NODE(&node35,&node55,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,-1,&node20);
  TEST_ASSERT_EQUAL_NODE(NULL,&node80,1,&node75);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node80);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);

}
/**
---------------------------------------remove 60----------------------------------------
*
*                               remove 40                           rotateleft at 50
*               40        ------------------->      45            ---------------->         45
*              /  \                                 / \                                    / \
*            20   50                               20  50                                 20  55
*           /    /  \                             /     \                                 /   / \
*         10    45   55                          10      55                             10   50  60
*                      \                                   \
*                       60                                 60
*
**/

void test_remove_testing(void){

  initIntegerNode(&node40,&node20,&node50,1);
  initIntegerNode(&node20,&node10,NULL,-1);
  initIntegerNode(&node50,&node45,&node55,1);
  initIntegerNode(&node55,NULL,&node60,1);
  initIntegerNode(&node10,NULL,NULL,0);
  initIntegerNode(&node45,NULL,NULL,0);
  initIntegerNode(&node60,NULL,NULL,0);


  Node *root = &node40;
  avlRemove(&root,40);
  TEST_ASSERT_EQUAL_PTR(&node45,root);
  TEST_ASSERT_EQUAL_NODE(&node20,&node55,0,&node45);;
  TEST_ASSERT_EQUAL_NODE(&node50,&node60,0,&node55);
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,-1,&node20);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node50);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node60);

}

/* Remove node 60
 *
 *                                                            130(0)
 *                                   /                                                        \
 *                               60(1)                                                        170(1)
 *                        /                  \                                        /                          \
 *                40(-1)                    105(-1)                               155(-1)                        210(-1)
 *              /        \             /            \                        /        \                    /              \
 *          30(-1)       55(-1)       80(1)         115(1)               145(-1)       165(-1)          185(1)               220(1)
 *          /    \        /        /   \         /     \               /      \         /              /    \               /     \
 *      25(-1)   35(0) 50(0)    75(-1)  90(1)   110(0)   120(1)      140(-1)   150(0) 160(0)       180(-1)   195(1)      215(0)    225(1)
 *       /                      /     /   \               \          /                               /       /   \                   \
 *    20(0)                 70(0) 85(0)  95(1)           125(0)   135(0)                         175(0) 190(0) 200(1)             230(0)
 *                                         \                                                                      \
 *                                       100(0)                                                                 205(0)
 *
 */
 void test_avlRemove_given_Node_above_delete_node60_expect_balance_tree3(void){
   Node *root= &node130;
   initIntegerNode(&node130,&node60,&node170,0);
   initIntegerNode(&node60,&node40,&node105,1);
   initIntegerNode(&node170,&node155,&node210,1);
   initIntegerNode(&node40,&node30,&node55,-1);
   initIntegerNode(&node105,&node80,&node155,1);
   initIntegerNode(&node155,&node145,&node165,-1);
   initIntegerNode(&node210,&node185,&node220,1);
   initIntegerNode(&node30,&node25,&node35,-1);
   initIntegerNode(&node55,&node50,NULL,-1);
   initIntegerNode(&node80,&node75,&node90,1);
   initIntegerNode(&node115,&node110,&node120,1);
   initIntegerNode(&node145,&node140,&node150,-1);
   initIntegerNode(&node165,&node160,NULL,-1);
   initIntegerNode(&node185,&node180,&node195,1);
   initIntegerNode(&node220,&node215,&node225,1);
   initIntegerNode(&node25,&node20,NULL,-1);
   initIntegerNode(&node35,NULL,NULL,0);
   initIntegerNode(&node50,NULL,NULL,0);
   initIntegerNode(&node75,&node70,NULL,-1);
   initIntegerNode(&node90,&node85,&node95,1);
   initIntegerNode(&node110,NULL,NULL,0);
   initIntegerNode(&node120,NULL,&node125,1);
   initIntegerNode(&node140,&node135,NULL,-1);
   initIntegerNode(&node150,NULL,NULL,0);
   initIntegerNode(&node160,NULL,NULL,0);
   initIntegerNode(&node180,&node175,NULL,-1);
   initIntegerNode(&node195,&node190,&node200,1);
   initIntegerNode(&node215,NULL,NULL,0);
   initIntegerNode(&node225,NULL,&node230,1);
   initIntegerNode(&node20,NULL,NULL,0);
   initIntegerNode(&node70,NULL,NULL,0);
   initIntegerNode(&node85,NULL,NULL,0);
   initIntegerNode(&node95,NULL,&node100,1);
   initIntegerNode(&node125,NULL,NULL,0);
   initIntegerNode(&node135,NULL,NULL,0);
   initIntegerNode(&node175,NULL,NULL,0);
   initIntegerNode(&node190,NULL,NULL,0);
   initIntegerNode(&node200,NULL,&node205,0);
   initIntegerNode(&node230,NULL,NULL,0);



   avlRemove(&root,60);
   TEST_ASSERT_EQUAL_PTR(&node130,root);
   TEST_ASSERT_EQUAL_NODE(&node70,&node170,1,&node130);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
   TEST_ASSERT_EQUAL_NODE(NULL,&node75,1,&node70);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);
 }

 void test_RemoveNode_given_40_remove_expect_NULL(void){


     initIntegerNode(&node40,NULL,NULL,0);

     Node *root = &node40;
     avlRemove(&root,40);
     TEST_ASSERT_EQUAL_PTR(NULL,root);
 }
 /**
 ---------------------------------remove 30------------------------------
 *       40(-1)                        40 (0)
 *       /          remove 40
 *     30 (0)  --------------->
 *
 **/
 void test_RemoveNode_given_40_with_child_30_delete_30_expect_40_only(void){

     initIntegerNode(&node30,NULL,NULL,0);
     initIntegerNode(&node40,&node30,NULL,-1);

     Node *root = &node40;
     avlRemove(&root,30);
     TEST_ASSERT_EQUAL_PTR(&node40,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
 }
 /**
 ---------------------------------remove 50------------------------------
 *       40(0)                              40 (-1)
 *       / \          remove 50            /
 *   30 (0) 50(0)   --------------->     30
 *
 **/
 void test_RemoveNode_given_40_with_child_30_50__delete_50_expect_40_30(void){

     initIntegerNode(&node50,NULL,NULL,0);
     initIntegerNode(&node30,NULL,NULL,0);
     initIntegerNode(&node40,&node30,&node50,0);

     Node *root = &node40;
     avlRemove(&root,50);
     TEST_ASSERT_EQUAL_PTR(&node40,root);
     TEST_ASSERT_EQUAL_NODE(&node30,NULL,-1,&node40);
 }

 /**
 ---------------------------------remove 50------------------------------
 *       40(-1)                            40 (-2)                                  30 (0)
 *       / \          remove 50          /                 rotate right           /  \
 *   30 (-1) 50(0)   --------------->   30(-1)            ------------>         20    40 (0)
 *   /                                 /
 *  20                               20
 *
 **/
 void test_RemoveNode_after_remove_rotate_right(void){

     initIntegerNode(&node50,NULL,NULL,0);
     initIntegerNode(&node20,NULL,NULL,0);
     initIntegerNode(&node30,&node20,NULL,-1);
     initIntegerNode(&node40,&node30,&node50,-1);

     Node *root = &node40;
     avlRemove(&root,50);
     TEST_ASSERT_EQUAL_PTR(&node30,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
     TEST_ASSERT_EQUAL_NODE(&node20,&node40,0,&node30);
 }
 /**
 ---------------------------------remove 50------------------------------
 *       40(-1)                            40 (-2)                                  30 (1)
 *       / \          remove 50          /                 rotate right           /  \
 *   30 (0) 50(0)   --------------->   30(0)            ------------>          20     40 (-1)
 *   / \                               / \                                            /
 *  20  35                           20  35                                          35
 *
 **/
 void test_RemoveNode_after_remove_rotate_right_condition2(void){

     initIntegerNode(&node50,NULL,NULL,0);
     initIntegerNode(&node35,NULL,NULL,0);
     initIntegerNode(&node20,NULL,NULL,0);
     initIntegerNode(&node30,&node20,&node35,0);
     initIntegerNode(&node40,&node30,&node50,-1);

     Node *root = &node40;
     avlRemove(&root,50);
     TEST_ASSERT_EQUAL_PTR(&node30,root);
     TEST_ASSERT_EQUAL_NODE(&node35,NULL,-1,&node40);
     TEST_ASSERT_EQUAL_NODE(&node20,&node40,1,&node30);
 }
 /**
 ---------------------------------remove 100       &           rotateLeftRight--------------------------------
 *           90(-1)                            90 (-2)                                        60 (0)
 *          / \          remove 100            /  \               rotateleftright           /  \
 *       50 (1) 95(1)   --------------->   50(1)   95[0]         ---------------->   (-1) 50  90 (0)
 *      / \     \                            / \                                          /    / \
 *  45   60 (1)   100(0)                    45  60 (1)                                   45   70   95
 *        \                                       \
 *        70                                       70
 *
 **/
 void test_remove_given_a_avltree_need_rotateLeftRight_after_remove_condition1_expect_balance(void){

      initIntegerNode(&node45,NULL,NULL,0);
      initIntegerNode(&node70,NULL,NULL,0);
      initIntegerNode(&node100,NULL,NULL,0);
      initIntegerNode(&node90,&node50,&node95,-1);
      initIntegerNode(&node95,NULL,&node100,1);
      initIntegerNode(&node50,&node45,&node60,1);
      initIntegerNode(&node60,NULL,&node70,1);

      Node *root = &node90;
      avlRemove(&root,100);
      TEST_ASSERT_EQUAL_PTR(&node60,root);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node70);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node95);
      TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
      TEST_ASSERT_EQUAL_NODE(&node45,NULL,-1,&node50);
      TEST_ASSERT_EQUAL_NODE(&node70,&node95,0,&node90);
 }
 /**
 ---------------------------------remove 100       &           rotateLeftRight--------------------------------
 *           90(-1)                            90 (-2)                                        60 (0)
 *          / \          remove 100            /  \               rotateleftright           /  \
 *       50 (1) 95(1)   --------------->   50(1)   95[0]         ---------------->   (0)   50   90 (1)
 *      / \     \                            / \                                          / \     \
 *  45   60 (-1) 100(0)                    45  60 (-1)                                   45  55    95
 *        /                                     /
 *       55                                    55
 *
 **/
 void test_remove_given_a_avltree_need_rotateLeftRight_after_remove_condition2_expect_balance(void){

      initIntegerNode(&node45,NULL,NULL,0);
      initIntegerNode(&node55,NULL,NULL,0);
      initIntegerNode(&node100,NULL,NULL,0);
      initIntegerNode(&node95,NULL,&node100,1);
      initIntegerNode(&node90,&node50,&node95,-1);
      initIntegerNode(&node50,&node45,&node60,1);
      initIntegerNode(&node60,&node55,NULL,-1);

      Node *root = &node90;
      avlRemove(&root,100);
      TEST_ASSERT_EQUAL_PTR(&node60,root);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node95);
      TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
      TEST_ASSERT_EQUAL_NODE(&node45,&node55,0,&node50);
      TEST_ASSERT_EQUAL_NODE(NULL,&node95,1,&node90);

 }
 /**
 ---------------------------------remove 100       &           rotateLeftRight--------------------------------
 *           90(-1)                            90 (-2)                                        60 (0)
 *          / \          remove 100            /  \               rotateleftright           /  \
 *       50 (1) 95(1)   --------------->   50(1)   95[0]         ---------------->   (0)   50   90 (0)
 *      / \     \                            / \                                          / \   / \
 *  45   60 (0) 100(0)                    45  60 (-1)                                   45  55 70 95
 *        / \                                 /  \
 *       55  70                              55  70
 *
 **/
 void test_remove_given_a_avltree_need_rotateLeftRight_after_remove_condition3_expect_balance(void){

      initIntegerNode(&node45,NULL,NULL,0);
      initIntegerNode(&node55,NULL,NULL,0);
      initIntegerNode(&node100,NULL,NULL,0);
      initIntegerNode(&node70,NULL,NULL,0);
      initIntegerNode(&node95,NULL,&node100,1);
      initIntegerNode(&node90,&node50,&node95,-1);
      initIntegerNode(&node50,&node45,&node60,1);
      initIntegerNode(&node60,&node55,&node70,0);

      Node *root = &node90;
      avlRemove(&root,100);
      TEST_ASSERT_EQUAL_PTR(&node60,root);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node95);
      TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
      TEST_ASSERT_EQUAL_NODE(&node45,&node55,0,&node50);
      TEST_ASSERT_EQUAL_NODE(&node70,&node95,0,&node90);

 }
 /**
 ---------------------------------remove 30 and rotateLeft---------------------------------
 *        40 (1)                            40 (+2)                             50
 *       /   \           remove 30            \                 rotate left    /   \
 *     30     50 (+1)   ---------->            50(1)        -------------->  40    100
 *            \                                 \
 *            100                               100
 *
 **/
 void test_remove_rotateleft1(void){

     initIntegerNode(&node30,NULL,NULL,0);
     initIntegerNode(&node100,NULL,NULL,0);
     initIntegerNode(&node50,NULL,&node100,1);
     initIntegerNode(&node40,&node30,&node50,1);

     Node *root = &node40;
     avlRemove(&root,30);
     TEST_ASSERT_EQUAL_PTR(&node50,root);
     TEST_ASSERT_EQUAL_NODE(&node40,&node100,0,&node50);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);

 }

 /**
 ---------------------------------remove 30 and rotateLeft---------------------------------
 *        40 (1)                            40 (+2)                             50
 *       /   \           remove 30            \                 rotate left    /   \
 *     30     50 (0)   ---------->            50(0)        -------------->  40    100
 *            /\                              /   \                          \
 *          45  100                         45   100                         45
 *
 **/
 void test_remove_rotateleft2(void){

     initIntegerNode(&node30,NULL,NULL,0);
     initIntegerNode(&node100,NULL,NULL,0);
     initIntegerNode(&node45,NULL,NULL,0);
     initIntegerNode(&node50,&node45,&node100,0);
     initIntegerNode(&node40,&node30,&node50,1);

     Node *root = &node40;
     avlRemove(&root,30);
     TEST_ASSERT_EQUAL_PTR(&node50,root);
     TEST_ASSERT_EQUAL_NODE(&node40,&node100,-1,&node50);
     TEST_ASSERT_EQUAL_NODE(NULL,&node45,1,&node40);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);


 }
 /**
 ---------------------------------remove 15 and rotateLeft---------------------------------
 *        30 (1)                            30 (2)                                   40
 *       /   \           remove 15         /  \                 rotateRightleft    /   \
 *     20     50 (-1)   ------------>    20    50(-1)        ----------------   30     50
 *    /       /\                              /   \                             / \      \
 *  15      40  100                         40   100                          20 35      100
 *         /                                /
 *       35                               35
 *
 *
 **/

 void test_remove_given_Avl_tree_remove_15_then_rotaterightleft_condition1_(void){

      initIntegerNode(&node15,NULL,NULL,0);
      initIntegerNode(&node35,NULL,NULL,0);
      initIntegerNode(&node100,NULL,NULL,0);
      initIntegerNode(&node40,&node35,NULL,-1);
      initIntegerNode(&node50,&node40,&node100,-1);
      initIntegerNode(&node30,&node20,&node50,1);
      initIntegerNode(&node20,&node15,NULL,-1);

      Node *root = &node30;
      avlRemove(&root,15);
      TEST_ASSERT_EQUAL_PTR(&node40,root);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
      TEST_ASSERT_EQUAL_NODE(&node30,&node50,0,&node40);
      TEST_ASSERT_EQUAL_NODE(NULL,&node100,1,&node50);
      TEST_ASSERT_EQUAL_NODE(&node20,&node35,0,&node30);
 }
 /**
 ---------------------------------remove 15 and rotateLeft---------------------------------
 *        30 (1)                            30 (2)                                   40
 *       /   \           remove 15         /  \                 rotateRightleft    /   \
 *     20     50 (-1)   ------------>    20    50(-1)        ----------------   30     50
 *    /       /\                              /   \                             / \    / \
 *  15      40  100                         40   100                          20 35  45    100
 *         / \                             / \
 *       35  45                           35 45
 *
 *
 **/
 void test_remove_given_Avl_tree_remove_15_then_rotaterightleft_condition2_(void){

      initIntegerNode(&node15,NULL,NULL,0);
      initIntegerNode(&node45,NULL,NULL,0);
      initIntegerNode(&node35,NULL,NULL,0);
      initIntegerNode(&node100,NULL,NULL,0);
      initIntegerNode(&node40,&node35,&node45,0);
      initIntegerNode(&node50,&node40,&node100,-1);
      initIntegerNode(&node30,&node20,&node50,1);
      initIntegerNode(&node20,&node15,NULL,-1);

      Node *root = &node30;
      avlRemove(&root,15);
      TEST_ASSERT_EQUAL_PTR(&node40,root);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
      TEST_ASSERT_EQUAL_NODE(&node30,&node50,0,&node40);
      TEST_ASSERT_EQUAL_NODE(&node45,&node100,0,&node50);
      TEST_ASSERT_EQUAL_NODE(&node20,&node35,0,&node30);
 }
 /**
 ---------------------------------remove 15 and rotateLeft---------------------------------
 *        30 (1)                            30 (2)                                   40
 *       /   \           remove 15         /  \                 rotateRightleft    /   \
 *     20     50 (-1)   ------------>    20    50(-1)        ----------------   30     50
 *    /       /\                              /   \                             /     /  \
 *  15      40  100                         40   100                          20   45   100
 *           \                              \
 *           45                              45
 *
 *
 **/
 void test_remove_given_Avl_tree_remove_15_then_rotaterightleft_condition3_(void){

      initIntegerNode(&node15,NULL,NULL,0);
      initIntegerNode(&node45,NULL,NULL,0);
      initIntegerNode(&node100,NULL,NULL,0);
      initIntegerNode(&node40,NULL,&node45,1);
      initIntegerNode(&node50,&node40,&node100,-1);
      initIntegerNode(&node30,&node20,&node50,1);
      initIntegerNode(&node20,&node15,NULL,-1);

      Node *root = &node30;
      avlRemove(&root,15);
      TEST_ASSERT_EQUAL_PTR(&node40,root);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
      TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
      TEST_ASSERT_EQUAL_NODE(&node30,&node50,0,&node40);
      TEST_ASSERT_EQUAL_NODE(&node45,&node100,0,&node50);
      TEST_ASSERT_EQUAL_NODE(&node20,NULL,-1,&node30);
 }
 /**
 ---------------------------------------remove 60----------------------------------------
 *        60                        80 (0)
 *      /  \       remove 60        /  \
 *    40    80    ---------->    40   100
 *           \
 *          100
 *
 *
 **/

 void test_remove_given_Avl_tree_remove_15_then_rotaterightleft_condition3(void){

   initIntegerNode(&node60,&node40,&node80,1);
   initIntegerNode(&node40,NULL,NULL,0);
   initIntegerNode(&node80,NULL,&node100,1);
   initIntegerNode(&node100,NULL,NULL,0);


   Node *root = &node60;
   avlRemove(&root,60);
   TEST_ASSERT_EQUAL_PTR(&node80,root);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
   TEST_ASSERT_EQUAL_NODE(&node40,&node100,0,&node80);
 }

 /**
 ---------------------------------------remove 60----------------------------------------
 *        60                         75 (0)
 *      /  \       remove 60        /  \
 *    40    90    ---------->    40     90
 *   /     /   \                 /      / \
 *  10    75    100            10      80  100
 *         \
 *           80
 **/

 void test_remove_given_Avl_tree_remove_60(void){

   initIntegerNode(&node60,&node40,&node90,1);
   initIntegerNode(&node40,&node10,NULL,-1);
   initIntegerNode(&node90,&node75,&node100,-1);
   initIntegerNode(&node10,NULL,NULL,0);
   initIntegerNode(&node75,NULL,&node80,1);
   initIntegerNode(&node80,NULL,NULL,0);
   initIntegerNode(&node100,NULL,NULL,0);


   Node *root = &node60;
   avlRemove(&root,60);
   TEST_ASSERT_EQUAL_PTR(&node75,root);
   TEST_ASSERT_EQUAL_NODE(&node40,&node90,0,&node75);
   TEST_ASSERT_EQUAL_NODE(&node10,NULL,-1,&node40);
   TEST_ASSERT_EQUAL_NODE(&node80,&node100,0,&node90);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node80);

 }

 /**
 -----------------remove 40----------------------
 *                   remove 40
 *        40 (0) ------------------>  NULL
 *
 **/
 void test_RemoveNode_test1(void){


     initIntegerNode(&node40,NULL,NULL,0);

     Node *root = &node40;
     avlRemove(&root,40);
     TEST_ASSERT_EQUAL_PTR(NULL,root);
 }

 /**
 ---------------------------------remove 30------------------------------
 *       40(-1)                        40 (0)
 *       /          remove 30
 *     30 (0)  --------------->
 *
 **/
 void test_RemoveNode_test2(void){


   initIntegerNode(&node30,NULL,NULL,0);
   initIntegerNode(&node40,&node30,NULL,-1);

   Node *root = &node40;
   avlRemove(&root,30);
   TEST_ASSERT_EQUAL_PTR(&node40,root);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
 }

 /**
 ---------------------------------remove 50------------------------------
 *       40(1)                        40 (0)
 *         \          remove 50
 *          50 (0)  --------------->
 *
 **/
 void test_RemoveNode_test3(void){


   initIntegerNode(&node50,NULL,NULL,0);
   initIntegerNode(&node40,NULL,&node50,1);

   Node *root = &node40;
   avlRemove(&root,50);
   TEST_ASSERT_EQUAL_PTR(&node40,root);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
 }

 /**
 ---------------------------------remove 50------------------------------
 *       40(0)                         40 (-1)
 *       / \          remove 50        /
 *    30    50 (0)  ---------------> 30
 *
 **/
 void test_RemoveNode_test4(void){


   initIntegerNode(&node30,NULL,NULL,0);
   initIntegerNode(&node50,NULL,NULL,0);
   initIntegerNode(&node40,&node30,&node50,0);


   Node *root = &node40;
   avlRemove(&root,50);
   TEST_ASSERT_EQUAL_PTR(&node40,root);
   TEST_ASSERT_EQUAL_NODE(&node30,NULL,-1,&node40);
 }

 /**
 ---------------------------------remove 30------------------------------
 *       40(0)                         40 (1)
 *       / \          remove 30         \
 *    30    50 (0)  --------------->    50
 *
 **/
 void test_RemoveNode_test5(void){


   initIntegerNode(&node30,NULL,NULL,0);
   initIntegerNode(&node50,NULL,NULL,0);
   initIntegerNode(&node40,&node30,&node50,0);


   Node *root = &node40;
   avlRemove(&root,30);
   TEST_ASSERT_EQUAL_PTR(&node40,root);
   TEST_ASSERT_EQUAL_NODE(NULL,&node50,1,&node40);
 }
 /**
 ---------------------------------remove 30------------------------------
 *       40(1)                           45 (0)
 *       / \          remove 30         /  \
 *    30    50 (-1)  --------------->  30    50
 *          /
 *         45
 **/
 void test_RemoveNode_test6(void){


   initIntegerNode(&node45,NULL,NULL,0);
   initIntegerNode(&node30,NULL,NULL,0);
   initIntegerNode(&node50,&node45,NULL,-1);
   initIntegerNode(&node40,&node30,&node50,1);


   Node *root = &node40;
   avlRemove(&root,40);
   TEST_ASSERT_EQUAL_PTR(&node45,root);
   TEST_ASSERT_EQUAL_NODE(&node30,&node50,0,&node45);
 }
 /**
 ---------------------------------------remove 60----------------------------------------
 *        60 (1)                           75 (0)
 *      /     \           remove 60        /  \
 * (-1)40      90 (-1)    ---------->    40     90
 *   /       /     \                    /      / \
 *  10     75 (1)   100               10      80  100
 *           \
 *           80
 **/

 void test_RemoveNode_test7(void){

   initIntegerNode(&node60,&node40,&node90,1);
   initIntegerNode(&node40,&node10,NULL,-1);
   initIntegerNode(&node90,&node75,&node100,-1);
   initIntegerNode(&node10,NULL,NULL,0);
   initIntegerNode(&node75,NULL,&node80,1);
   initIntegerNode(&node80,NULL,NULL,0);
   initIntegerNode(&node100,NULL,NULL,0);


   Node *root = &node60;
   avlRemove(&root,60);
   TEST_ASSERT_EQUAL_PTR(&node75,root);
   TEST_ASSERT_EQUAL_NODE(&node40,&node90,0,&node75);
   TEST_ASSERT_EQUAL_NODE(&node10,NULL,-1,&node40);
   TEST_ASSERT_EQUAL_NODE(&node80,&node100,0,&node90);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node80);

 }
 /**
 ---------------------------------------remove 60----------------------------------------
 *        60                         75 (1)
 *      /  \       remove 60        /  \
 *    40    90    ---------->     40    90(1)
 *         /   \                         \
 *        75    100                     100
 *
 *
 **/

 void test_remove_given_Avl_tree_remove_60_test1(void){

   initIntegerNode(&node60,&node40,&node90,1);
   initIntegerNode(&node40,NULL,NULL,0);
   initIntegerNode(&node90,&node75,&node100,0);
   initIntegerNode(&node75,NULL,NULL,0);
   initIntegerNode(&node100,NULL,NULL,0);


   Node *root = &node60;
   avlRemove(&root,60);
   TEST_ASSERT_EQUAL_PTR(&node75,root);
   TEST_ASSERT_EQUAL_NODE(&node40,&node90,1,&node75);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
   TEST_ASSERT_EQUAL_NODE(NULL,&node100,1,&node90);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);

 }
 /**
 ---------------------------------------remove 40----------------------------------------
 *         60
 *      /     \       remove 40
 *    40        90    ---------->
 *    / \     /   \
 *   20  50  75    100
 *         \
 *          55
 **/

 void test_remove_test8(void){

   initIntegerNode(&node60,&node40,&node90,-1);
   initIntegerNode(&node40,&node20,&node50,1);
   initIntegerNode(&node90,&node75,&node100,0);
   initIntegerNode(&node50,NULL,&node55,1);
   initIntegerNode(&node75,NULL,NULL,0);
   initIntegerNode(&node20,NULL,NULL,0);
   initIntegerNode(&node100,NULL,NULL,0);
   initIntegerNode(&node55,NULL,NULL,0);


   Node *root = &node60;
   avlRemove(&root,40);
   TEST_ASSERT_EQUAL_PTR(&node60,root);
   TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
   TEST_ASSERT_EQUAL_NODE(&node20,&node55,0,&node50);
   TEST_ASSERT_EQUAL_NODE(&node75,&node100,0,&node90);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
   TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);

 }
