#include "unity.h"
#include "AvlString.h"
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

StringNode nodeAli,nodeAbu,nodeAkau,nodeAlirosa,nodeAba,nodeAmin;
CEXCEPTION_T ex;


#define initStringNode(n,l,r,bf)  initNode((Node *)n,(Node *)l,(Node *)r,bf)

void setUp(void)
{
  nodeAli.data="Ali";
  nodeAbu.data="Abu";
  nodeAkau.data="Akau";
  nodeAlirosa.data="Alirosa";
  nodeAba.data="Aba";
  nodeAmin.data="Amin";
}

void tearDown(void){}


/* Add same node
 *     Ali    -------->     Error code 1
 *
 */
void test_AVL_StringAdd_given_Ali_add_Ali_expected_error_code_1(void){
  initStringNode(&nodeAli,NULL,NULL,0);
  StringNode *root = &nodeAli;
  Try{
  avlAddString(&root,&nodeAli);
  TEST_ASSERT_EQUAL(1,ex);
  }Catch(ex){
  }
}

/* Add Ali
 *      NULL    -------->       "Ali" (0)
 *
 */
void test_AVL_StringAdd_given_NULL_add_Ali(void){
  initStringNode(&nodeAli,NULL,NULL,0);
  StringNode *root = NULL;
  Try{
  avlAddString(&root,&nodeAli);
  TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
  TEST_ASSERT_EQUAL_STRING_NODE(NULL,NULL,0,&nodeAli);
  }Catch(ex){
    dumpException(ex);
  }
}

/* Add Amin
 *      "Ali" (0)    -------->       "Ali" (+1)
 *                                       \
 *                                        "Amin"(0)
 */
void test_AVL_StringAdd_given_Ali_add_Amin(void){
  initStringNode(&nodeAli,NULL,NULL,0);
  initStringNode(&nodeAmin,NULL,NULL,0);
  StringNode *root = &nodeAli;
  Try{
  avlAddString(&root,&nodeAmin);
  TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
  TEST_ASSERT_EQUAL_STRING_NODE(NULL,&nodeAmin,1,&nodeAli);
  }Catch(ex){
    dumpException(ex);
  }
}

/* Add Abu
 *      "Ali" (+1)                                      "Ali" (0)
 *          \                       ------->           /      \
 *         "Amin"(0)                             "Abu"(0)   "Amin"(0)
 */
void test_AVL_StringAdd_given_Ali_Amin_add_Abu(void){
  initStringNode(&nodeAli,NULL,&nodeAmin,1);
  initStringNode(&nodeAmin,NULL,NULL,0);
  initStringNode(&nodeAbu,NULL,NULL,0);
  StringNode *root = &nodeAli;
  Try{
  avlAddString(&root,&nodeAbu);
  TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
  TEST_ASSERT_EQUAL_STRING_NODE(&nodeAbu,&nodeAmin,0,&nodeAli);
  }Catch(ex){
    dumpException(ex);
  }
}

/* Remove Amin
 *           "Ali" (0)                                        "Ali" (-1)
 *           /      \               ---------->               /
 *     "Abu"(0)   "Amin"(0)                               "Abu"(0)
 */
void test_AVL_StringRemove_given_Ali_Abu_Amin_remove_Amin(void){
  initStringNode(&nodeAli,&nodeAbu,&nodeAmin,0);
  initStringNode(&nodeAmin,NULL,NULL,0);
  initStringNode(&nodeAbu,NULL,NULL,0);
  StringNode *root = &nodeAli;

  Try{
  avlRemoveString(&root,"Amin");
  TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
  TEST_ASSERT_EQUAL_STRING_NODE(&nodeAbu,NULL,-1,&nodeAli);
  }Catch(ex){
    dumpException(ex);
  }
}


/* Remove Abu
 *           "Ali" (0)                                        "Ali" (1)
 *           /      \               ---------->                   \
 *     "Abu"(0)   "Amin"(0)                                     "Amin"(0)
 */
void test_AVL_StringRemove_given_Ali_Abu_Amin_remove_Abu(void){
  initStringNode(&nodeAli,&nodeAbu,&nodeAmin,0);
  initStringNode(&nodeAmin,NULL,NULL,0);
  initStringNode(&nodeAbu,NULL,NULL,0);
  StringNode *root = &nodeAli;

  Try{
  avlRemoveString(&root,"Abu");
  TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
  TEST_ASSERT_EQUAL_STRING_NODE(NULL,&nodeAmin,1,&nodeAli);
  }Catch(ex){
    dumpException(ex);
  }
}
