#ifndef _NODEVERIFIER_H
#define _NODEVERIFIER_H
#include "Node.h"

#define TEST_ASSERT_EQUAL_INTEGER_NODE(left,right,bf,node) \
                          testAssertEqualNode(left,right,bf,node,__LINE__)


void testAssertEqualNode(intNode *left, intNode *right, int bf, intNode *node,int lineNo);

#endif // _NODEVERIFIER_H
