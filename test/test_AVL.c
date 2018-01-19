#include "unity.h"
#include "AVL.h"
#include "Node.h"
#include "NodeHelper.h"
#include "NodeVerifier.h"
#include "AvlInteger.h"
#include <stdint.h>
#include <stdio.h>
#include "Rotate.h"
#include "Exception.h"
#include "CException.h"

intNode node1, node5, node10, node15, node20, node25, node30, node35, node40;
intNode node45, node50, node55,node60,node65,node70,node75,node80,node85,node90;
intNode node95,node100,node105,node110,node115,node120,node125,node130,node135;
intNode node140,node145,node150,node155,node160,node165,node170,node175,node180;
intNode node185,node190,node195,node200,node205,node210,node215,node220,node225,node230;

#define initIntegerNode(n,l,r,bf)  initNode((Node *)n,(Node *)l,(Node *)r,bf)

CEXCEPTION_T ex;

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
void test_avlAdd_given_IntegerNode50_add_IntegerNode50_expected_error_code_1(void){
  intNode *root = &node50;
  initIntegerNode(&node50,NULL,NULL,0);
  Try{
  avlAddInteger(&root, &node50);

  }Catch(ex){
    TEST_ASSERT_EQUAL(1,ex->errorCode);
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node50);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node55);
}

/**
 *   (add 55):
 *              50
 *               \
 *                55
 */
void test_avlAdd_given_root_node50_add_node55_expected_balance_tree(void){
  intNode *root = &node50;
  initIntegerNode(&node50,NULL,NULL,0);
  initIntegerNode(&node55,NULL,NULL,0);
  Try{
    avlAddInteger(&root, &node55);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,&node55,1,&node50);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node55);
}

/**
 *        add 50
 *    NULL-------> 50
 */
void test_avlAdd_given_empty_tree_add_node1_expected_node1_to_be_root(void){
  intNode *root = NULL;
  initIntegerNode(&node50,NULL,NULL,0);
  Try{
    avlAddInteger(&root, &node50);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node50);
}


/**
 *   (add 40):
 *              55
 *             /
 *            40
 */
void test_avlAdd_given_root_node55_add_node40_expected_balance_tree(void){
  intNode *root = &node55;
  initIntegerNode(&node55,NULL,NULL,0);
  initIntegerNode(&node40,NULL,NULL,0);

  Try{
  avlAddInteger(&root, &node40);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node55,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node40,NULL,-1,&node55);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node40);
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
  intNode *root = &node55;
  initIntegerNode(&node55,&node40,NULL,-1);
  initIntegerNode(&node40,NULL,NULL,0);
  initIntegerNode(&node35,NULL,NULL,0);

  Try{
  avlAddInteger(&root, &node35);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node40,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node35,&node55,0,&node40);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node35);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node55);
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
  intNode *root = &node55;
  initIntegerNode(&node55,&node40,NULL,-1);
  initIntegerNode(&node40,NULL,NULL,0);
  initIntegerNode(&node45,NULL,NULL,0);

  Try{
  avlAddInteger(&root, &node45);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node45,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node40,&node55,0,&node45);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node55);
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
  intNode *root = &node55;
  initIntegerNode(&node55,NULL,&node65,1);
  initIntegerNode(&node65,NULL,NULL,0);
  initIntegerNode(&node60,NULL,NULL,0);

  Try{
  avlAddInteger(&root, &node60);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node60,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node55,&node65,0,&node60);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node65);
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
  intNode *root = &node55;
  initIntegerNode(&node55,NULL,&node65,1);
  initIntegerNode(&node65,NULL,NULL,0);
  initIntegerNode(&node70,NULL,NULL,0);

  Try{
  avlAddInteger(&root, &node70);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node65,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node55,&node70,0,&node65);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node70);
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
  intNode *root = &node55;
  initIntegerNode(&node55,&node40,&node60,-1);
  initIntegerNode(&node40,&node35,NULL,-1);
  initIntegerNode(&node60,NULL,NULL,0);
  initIntegerNode(&node35,NULL,NULL,0);
  initIntegerNode(&node45,NULL,NULL,0);

  Try{
   avlAddInteger(&root, &node45);
  }Catch(ex){
   dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node55,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node45);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node35);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node60);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node35,&node45,0,&node40);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node40,&node60,-1,&node55);
}

/*
 *   (add 35):
 *           55                   55
 *          /  \                 / \
 *         40  60    ---->     40  60
 *          \                 / \
 *          45              35  45
 */
void test_avlAdd_given_root_node55_and_node40_node60_node45_add_node35_expected_balance_tree(void){
  intNode *root = &node55;
  initIntegerNode(&node55,&node40,&node60,-1);
  initIntegerNode(&node40,NULL,&node45,1);
  initIntegerNode(&node60,NULL,NULL,0);
  initIntegerNode(&node35,NULL,NULL,0);
  initIntegerNode(&node45,NULL,NULL,0);

  Try{
    avlAddInteger(&root, &node35);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node55,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node45);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node35);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node60);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node35,&node45,0,&node40);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node40,&node60,-1,&node55);
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
  intNode *root = &node55;
  initIntegerNode(&node55,&node40,&node65,1);
  initIntegerNode(&node40,NULL,NULL,0);
  initIntegerNode(&node65,NULL,&node75,1);
  initIntegerNode(&node75,NULL,NULL,0);
  initIntegerNode(&node60,NULL,NULL,0);

  Try{
    avlAddInteger(&root, &node60);
  }Catch(ex){
     dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node55,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node60);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node75);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node60,&node75,0,&node65);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node40,&node65,1,&node55);
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
  intNode *root = &node55;
  initIntegerNode(&node55,&node40,&node65,1);
  initIntegerNode(&node40,NULL,NULL,0);
  initIntegerNode(&node65,&node60,NULL,-1);
  initIntegerNode(&node75,NULL,NULL,0);
  initIntegerNode(&node60,NULL,NULL,0);

  Try{
    avlAddInteger(&root, &node75);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node55,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node60);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node75);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node60,&node75,0,&node65);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node40,&node65,1,&node55);
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
  intNode *root = &node55;
  initIntegerNode(&node55,&node40,&node65,1);
  initIntegerNode(&node40,NULL,NULL,0);
  initIntegerNode(&node65,&node60,&node75,0);
  initIntegerNode(&node75,NULL,NULL,0);
  initIntegerNode(&node60,NULL,NULL,0);
  initIntegerNode(&node80,NULL,NULL,0);

  Try{
    avlAddInteger(&root, &node80);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node65,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node60);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node80);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node55,&node75,0,&node65);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node40,&node60,0,&node55);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,&node80,1,&node75);
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
  intNode *root = &node50;
  initIntegerNode(&node50,&node40,&node65,1);
  initIntegerNode(&node40,NULL,NULL,0);
  initIntegerNode(&node65,&node55,&node75,0);
  initIntegerNode(&node75,NULL,NULL,0);
  initIntegerNode(&node55,NULL,NULL,0);
  initIntegerNode(&node80,NULL,NULL,0);
  initIntegerNode(&node60,NULL,NULL,0);

  Try{
  avlAddInteger(&root, &node60);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(&node55,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node60);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node75);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node40,NULL,-1,&node50);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node60,&node75,0,&node65);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node50,&node65,0,&node55);
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
   intNode *root = &node55;
   initIntegerNode(&node55,&node40,&node65,1);
   initIntegerNode(&node40,&node30,NULL,-1);
   initIntegerNode(&node65,&node60,&node75,1);
   initIntegerNode(&node75,NULL,&node80,1);
   initIntegerNode(&node30,NULL,NULL,0);
   initIntegerNode(&node80,NULL,NULL,0);
   initIntegerNode(&node60,NULL,NULL,0);
   initIntegerNode(&node85,NULL,NULL,0);

   Try{
     avlAddInteger(&root, &node85);
   }Catch(ex){
     dumpException(ex);
   }
   TEST_ASSERT_EQUAL_PTR(&node55,root);
   TEST_ASSERT_EQUAL_INTEGER_NODE(&node30,NULL,-1,&node40);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node30);
   TEST_ASSERT_EQUAL_INTEGER_NODE(&node60,&node80,1,&node65);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node60);
   TEST_ASSERT_EQUAL_INTEGER_NODE(&node75,&node85,0,&node80);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node85);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node75);

}

/* Remove 30
 *       40(0)    -------->   Exception Thrown
 */
void test_RemoveNode_given_Tree_contain_only_node40_remove_node30_expect_errorCode_2(void){
   intNode *root = &node40;
   initIntegerNode(&node40,NULL,NULL,0);

   Try{
     avlRemoveInteger(&root,30);
   }Catch(ex){
     TEST_ASSERT_EQUAL(2,ex->errorCode);
     dumpException(ex);
   }
   TEST_ASSERT_EQUAL_PTR(&node40,root);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node40);
}

/* Remove 40
 *       40(0)    -------->   NULL
 */
void test_RemoveNode_given_40_remove_expect_NULL(void){
   intNode *root = &node40;
   initIntegerNode(&node40,NULL,NULL,0);

   avlRemoveInteger(&root,40);
   TEST_ASSERT_EQUAL_PTR(NULL,root);
}


/* Remove node 40
 *          50(-1)           50(0)
 *         /         --->
 *       40(0)
 */
void test_avlRemove_given_node50_and_node40_delete_node40_expect_left_node50(void){
  intNode *root= &node50;
  initIntegerNode(&node50,&node40,NULL,-1);
  initIntegerNode(&node40,NULL,NULL,0);

  avlRemoveInteger(&root,40);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node50);
}

/* Remove node 55
 *          50(0)              50(-1)
 *         /   \      --->    /
 *     40(0)  55(0)        40(0)
 */
void test_avlRemove_given_node50_and_node40_node55_delete_node55_expect_left_node50_node_40(void){
  intNode *root= &node50;
  initIntegerNode(&node50,&node40,&node55,0);
  initIntegerNode(&node40,NULL,NULL,0);
  initIntegerNode(&node55,NULL,NULL,0);

  avlRemoveInteger(&root,55);
  TEST_ASSERT_EQUAL_PTR(&node50,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node40,NULL,-1,&node50);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node40);
}

/* Remove node 55
 *          50(-1)              50(-2)                    40(0)
 *         /   \      --->    /             ---->        /   \
 *     40(-1)  55(0)        40(-1)                    35(0) 50(0)
 *      /                   /
 *   35(0)                35(0)
 */
void test_avlRemove_given_node50_and_node40_node35_node55_delete_node55_expect_balance_tree(void){
  intNode *root= &node50;
  initIntegerNode(&node50,&node40,&node55,-1);
  initIntegerNode(&node40,&node35,NULL,-1);
  initIntegerNode(&node35,NULL,NULL,0);
  initIntegerNode(&node55,NULL,NULL,0);

  avlRemoveInteger(&root,55);
  TEST_ASSERT_EQUAL_PTR(&node40,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node35,&node50,0,&node40);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node35);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node50);
}

/* Remove node 55
 *          50(-1)              50(-2)                    40(1)
 *         /   \      --->    /             ---->        /    \
 *     40(0)  55(0)        40(-1)                    35(0)   50(-1)
 *     /  \               /   \                              /
 * 35(0) 45(0)         35(0) 45(0)                         45(0)
 */
void test_avlRemove_given_node50_and_node40_node35_node45_node55_delete_node55_expect_balance_tree(void){
  intNode *root= &node50;
  initIntegerNode(&node50,&node40,&node55,-1);
  initIntegerNode(&node40,&node35,&node45,0);
  initIntegerNode(&node35,NULL,NULL,0);
  initIntegerNode(&node45,NULL,NULL,0);
  initIntegerNode(&node55,NULL,NULL,0);

  avlRemoveInteger(&root,55);
  TEST_ASSERT_EQUAL_PTR(&node40,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node35,&node50,1,&node40);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node35);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node45,NULL,-1,&node50);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node45);
}

/* Remove node 40
 *          50(-1)              50(-1)
 *         /   \      --->    /     \
 *     40(0)  55(0)        45(-1)   55(0)
 *     /  \                /
 * 35(0) 45(0)           35(0)
 */
 void test_avlRemove_given_node50_and_node40_node35_node45_node55_delete_node40_expect_balance_tree(void){
   intNode *root= &node50;
   initIntegerNode(&node50,&node40,&node55,-1);
   initIntegerNode(&node40,&node35,&node45,0);
   initIntegerNode(&node35,NULL,NULL,0);
   initIntegerNode(&node45,NULL,NULL,0);
   initIntegerNode(&node55,NULL,NULL,0);

   avlRemoveInteger(&root,40);
   TEST_ASSERT_EQUAL_PTR(&node50,root);
   TEST_ASSERT_EQUAL_INTEGER_NODE(&node45,&node55,-1,&node50);
   TEST_ASSERT_EQUAL_INTEGER_NODE(&node35,NULL,-1,&node45);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node55);
}

/* Remove node 35
 *          50(-1)              50(-1)
 *         /   \      --->    /     \
 *     40(0)  55(0)        40(+1)   55(0)
 *     /  \                   \
 * 35(0) 45(0)                45(0)
 */
 void test_avlRemove_given_node50_and_node40_node35_node45_node55_delete_node35_expect_balance_tree(void){
   intNode *root= &node50;
   initIntegerNode(&node50,&node40,&node55,-1);
   initIntegerNode(&node40,&node35,&node45,0);
   initIntegerNode(&node35,NULL,NULL,0);
   initIntegerNode(&node45,NULL,NULL,0);
   initIntegerNode(&node55,NULL,NULL,0);

   avlRemoveInteger(&root,35);
   TEST_ASSERT_EQUAL_PTR(&node50,root);
   TEST_ASSERT_EQUAL_INTEGER_NODE(&node40,&node55,-1,&node50);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,&node45,1,&node40);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node55);
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
   intNode *root= &node50;
   initIntegerNode(&node50,&node40,&node70,1);
   initIntegerNode(&node40,&node35,NULL,-1);
   initIntegerNode(&node70,&node55,&node75,-1);
   initIntegerNode(&node35,NULL,NULL,0);
   initIntegerNode(&node55,NULL,&node60,1);
   initIntegerNode(&node75,NULL,NULL,0);
   initIntegerNode(&node60,NULL,NULL,0);

   avlRemoveInteger(&root,50);
   TEST_ASSERT_EQUAL_PTR(&node55,root);
   TEST_ASSERT_EQUAL_INTEGER_NODE(&node40,&node70,0,&node55);
   TEST_ASSERT_EQUAL_INTEGER_NODE(&node35,NULL,-1,&node40);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node35);
   TEST_ASSERT_EQUAL_INTEGER_NODE(&node60,&node75,0,&node70);
   TEST_ASSERT_EQUAL_INTEGER_NODE(&node60,&node75,0,&node70);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node60);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node75);
}

/* Remove node 50
 *          50(1)                  70(0)
 *         /   \      --->        /    \
 *      40(0)  70(1)            40(0)   75(0)
 *                \
 *               75(0)
 */
 void test_avlRemove_given_Node_above_delete_node50_expect_balance_tree_1(void){
   intNode *root= &node50;
   initIntegerNode(&node50,&node40,&node70,1);
   initIntegerNode(&node40,NULL,NULL,0);
   initIntegerNode(&node70,NULL,&node75,1);
   initIntegerNode(&node75,NULL,NULL,0);

   avlRemoveInteger(&root,50);
   TEST_ASSERT_EQUAL_PTR(&node70,root);
   TEST_ASSERT_EQUAL_INTEGER_NODE(&node40,&node75,0,&node70);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node40);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node75);
}

/* Remove node 50
 *          50(1)                  65(1)
 *         /   \      --->        /    \
 *      40(0)  70(0)           40(0)   70(1)
 *             /  \                      \
 *          65(0) 75(0)                 75(0)
 */
void test_avlRemove_given_Node_above_delete_node50_expect_balance_tree_2(void){
   intNode *root= &node50;
   initIntegerNode(&node50,&node40,&node70,1);
   initIntegerNode(&node40,NULL,NULL,0);
   initIntegerNode(&node70,&node65,&node75,0);
   initIntegerNode(&node65,NULL,NULL,0);
   initIntegerNode(&node75,NULL,NULL,0);

   avlRemoveInteger(&root,50);
   TEST_ASSERT_EQUAL_PTR(&node65,root);
   TEST_ASSERT_EQUAL_INTEGER_NODE(&node40,&node70,1,&node65);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node40);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,&node75,1,&node70);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node75);
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
   intNode *root= &node50;
   initIntegerNode(&node50,&node40,&node70,1);
   initIntegerNode(&node40,&node35,NULL,-1);
   initIntegerNode(&node70,&node65,&node75,1);
   initIntegerNode(&node35,NULL,NULL,0);
   initIntegerNode(&node65,NULL,NULL,0);
   initIntegerNode(&node75,NULL,&node80,1);
   initIntegerNode(&node80,NULL,NULL,0);

   avlRemoveInteger(&root,35);
   TEST_ASSERT_EQUAL_PTR(&node70,root);
   TEST_ASSERT_EQUAL_INTEGER_NODE(&node50,&node75,0,&node70);
   TEST_ASSERT_EQUAL_INTEGER_NODE(&node40,&node65,0,&node50);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node40);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node65);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,&node80,1,&node75);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node80);
}


/* Remove node 50
 *          50(-1)                  40(0)
 *         /       --->
 *     40(0)
 *
 */
 void test_avlRemove_given_Node_above_delete_node50_expected_balance_tree(void){
   intNode *root= &node50;
   initIntegerNode(&node50,&node40,NULL,-1);
   initIntegerNode(&node40,NULL,NULL,0);

   avlRemoveInteger(&root,50);
   TEST_ASSERT_EQUAL_PTR(&node40,root);
   TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node40);
}

/* Remove 40
 *
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
 */
void test_avlRemove_given_Node_above_remove_60_expected_balanced_tree(void){
  intNode *root = &node60;
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

  avlRemoveInteger(&root,40);
  TEST_ASSERT_EQUAL_PTR(&node60,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node30,&node90,0,&node60);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node20,&node50,0,&node30);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node75,&node100,-1,&node90);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node35,&node55,0,&node50);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node10,NULL,-1,&node20);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,&node80,1,&node75);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node10);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node35);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node80);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node100);
}

/* remove 40
 *
 *               40        ------------------->      45            ---------------->         45
 *              /  \                                 / \                                    / \
 *            20   50                               20  50                                 20  55
 *           /    /  \                             /     \                                 /   / \
 *         10    45   55                          10      55                             10   50  60
 *                      \                                   \
 *                       60                                 60
 *
 */
void test_given_tree_above_remove_40_expeceted_balanced_tree(void){
  intNode *root = &node40;
  initIntegerNode(&node40,&node20,&node50,1);
  initIntegerNode(&node20,&node10,NULL,-1);
  initIntegerNode(&node50,&node45,&node55,1);
  initIntegerNode(&node55,NULL,&node60,1);
  initIntegerNode(&node10,NULL,NULL,0);
  initIntegerNode(&node45,NULL,NULL,0);
  initIntegerNode(&node60,NULL,NULL,0);

  avlRemoveInteger(&root,40);
  TEST_ASSERT_EQUAL_PTR(&node45,root);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node20,&node55,0,&node45);;
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node50,&node60,0,&node55);
  TEST_ASSERT_EQUAL_INTEGER_NODE(&node10,NULL,-1,&node20);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node10);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node50);
  TEST_ASSERT_EQUAL_INTEGER_NODE(NULL,NULL,0,&node60);
}
