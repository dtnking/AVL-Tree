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


StringNode nodeAli,nodeAbu,nodeAkau,nodeAlirosa,nodeAba,nodeAmin;


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

void tearDown(void)
{
}


 void test_AVL_StringAdd(void){
   initStringNode(&nodeAli,NULL,NULL,0);
   initStringNode(&nodeAmin,NULL,NULL,0);
   StringNode *root = &nodeAli;

   avlAddString(&root,&nodeAmin);
   TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
   TEST_ASSERT_EQUAL_STRING_NODE(NULL,&nodeAmin,1,&nodeAli);
   avlAddString(&root,&nodeAbu);
   TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
   TEST_ASSERT_EQUAL_STRING_NODE(&nodeAbu,&nodeAmin,0,&nodeAli);
 }

 void test_AVL_StringRemove(void){
   initStringNode(&nodeAli,&nodeAbu,&nodeAmin,0);
   initStringNode(&nodeAmin,NULL,NULL,0);
   initStringNode(&nodeAbu,NULL,NULL,0);
   StringNode *root = &nodeAli;

   avlRemoveString(&root,"Amin");
   TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
   TEST_ASSERT_EQUAL_PTR(&nodeAbu,nodeAli.left);
   TEST_ASSERT_EQUAL_PTR(NULL,nodeAli.right);
   TEST_ASSERT_EQUAL_STRING_NODE(&nodeAbu,NULL,-1,&nodeAli);
   avlRemoveString(&root,"Abu");
   TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
   TEST_ASSERT_EQUAL_STRING_NODE(NULL,NULL,0,&nodeAli);
 }
