#include "unity.h"
#include "AVL.h"
#include "Node.h"
#include "NodeHelper.h"

void setUp(void){}

void tearDown(void){}


/**
 *        add 50
 *    NULL-------> 50
 */
void test_avlAdd_given_empty_tree_add_node1_expect_node1_to_be_root(void){
  Node *root = NULL;
  initMode(&node50,&node40,&node55,100);

  avlAdd(&root, &node50);

}
