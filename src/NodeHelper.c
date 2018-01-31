#include "unity.h"
#include "Node.h"
#include "NodeHelper.h"

intNode node1, node5, node10, node15, node20, node25, node30, node35, node40;
intNode node45, node50, node55,node60,node65,node70,node75,node80,node85,node90;
intNode node95,node100,node105,node110,node115,node120,node125,node130,node135;
intNode node140,node145,node150,node155,node160,node165,node170,node175,node180;
intNode node185,node190,node195,node200,node205,node210,node215,node220,node225,node230,node250;

StringNode nodeAli,nodeAbu,nodeAkau,nodeAlirosa,nodeAba,nodeAmin;

#define initIntegerNode(n,l,r,bf)  initNode((Node *)n,(Node *)l,(Node *)r,bf)
#define initStringNode(n,l,r,bf)  initNode((Node *)n,(Node *)l,(Node *)r,bf)

void initNode(Node *node, Node *left, Node *right, int bf){
  node->left = left;
  node->right = right;
  node->balanceFactor = bf;
}

void intNodeNullify(void){
  initIntegerNode(&node1,NULL,NULL,0);
  initIntegerNode(&node5,NULL,NULL,0);
  initIntegerNode(&node10,NULL,NULL,0);
  initIntegerNode(&node15,NULL,NULL,0);
  initIntegerNode(&node20,NULL,NULL,0);
  initIntegerNode(&node25,NULL,NULL,0);
  initIntegerNode(&node30,NULL,NULL,0);
  initIntegerNode(&node35,NULL,NULL,0);
  initIntegerNode(&node40,NULL,NULL,0);
  initIntegerNode(&node45,NULL,NULL,0);
  initIntegerNode(&node50,NULL,NULL,0);
  initIntegerNode(&node55,NULL,NULL,0);
  initIntegerNode(&node60,NULL,NULL,0);
  initIntegerNode(&node65,NULL,NULL,0);
  initIntegerNode(&node70,NULL,NULL,0);
  initIntegerNode(&node75,NULL,NULL,0);
  initIntegerNode(&node80,NULL,NULL,0);
  initIntegerNode(&node85,NULL,NULL,0);
  initIntegerNode(&node90,NULL,NULL,0);
  initIntegerNode(&node95,NULL,NULL,0);
  initIntegerNode(&node100,NULL,NULL,0);
  initIntegerNode(&node105,NULL,NULL,0);
  initIntegerNode(&node110,NULL,NULL,0);
  initIntegerNode(&node115,NULL,NULL,0);
  initIntegerNode(&node120,NULL,NULL,0);
  initIntegerNode(&node125,NULL,NULL,0);
  initIntegerNode(&node130,NULL,NULL,0);
  initIntegerNode(&node135,NULL,NULL,0);
  initIntegerNode(&node140,NULL,NULL,0);
  initIntegerNode(&node145,NULL,NULL,0);
  initIntegerNode(&node150,NULL,NULL,0);
  initIntegerNode(&node155,NULL,NULL,0);
  initIntegerNode(&node160,NULL,NULL,0);
  initIntegerNode(&node165,NULL,NULL,0);
  initIntegerNode(&node170,NULL,NULL,0);
  initIntegerNode(&node175,NULL,NULL,0);
  initIntegerNode(&node180,NULL,NULL,0);
  initIntegerNode(&node185,NULL,NULL,0);
  initIntegerNode(&node190,NULL,NULL,0);
  initIntegerNode(&node200,NULL,NULL,0);
  initIntegerNode(&node205,NULL,NULL,0);
  initIntegerNode(&node210,NULL,NULL,0);
  initIntegerNode(&node215,NULL,NULL,0);
  initIntegerNode(&node220,NULL,NULL,0);
  initIntegerNode(&node225,NULL,NULL,0);
  initIntegerNode(&node230,NULL,NULL,0);
  initIntegerNode(&node250,NULL,NULL,0);
}

void strNodeNullify(void){
  initStringNode(&nodeAli,NULL,NULL,0);
  initStringNode(&nodeAbu,NULL,NULL,0);
  initStringNode(&nodeAkau,NULL,NULL,0);
  initStringNode(&nodeAlirosa,NULL,NULL,0);
  initStringNode(&nodeAba,NULL,NULL,0);
  initStringNode(&nodeAmin,NULL,NULL,0);
}
