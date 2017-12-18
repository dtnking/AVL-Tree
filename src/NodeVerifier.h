#ifndef _NODEVERIFIER_H
#define _NODEVERIFIER_H
#include "Node.h"

#define TEST_ASSERT_EQUAL_INTEGER_NODE(left,right,bf,node) \
                          testAssertEqualNode((Node *)left,(Node *)right,bf,(Node *)node,__LINE__)

#define TEST_ASSERT_EQUAL_STRING_NODE(left,right,bf,node) \
                                                    testAssertEqualNode((Node *)left,(Node *)right,bf,(Node *)node,__LINE__)
// void testAssertEqualNode(intNode *left, intNode *right, int bf, intNode *node,int lineNo);

#define TEST_ASSERT_EQUAL_NODE(left,right,bf,node) \
                                                    testAssertEqualNode((Node *)left,(Node *)right,bf,(Node *)node,__LINE__)

void testAssertEqualNode(Node *left, Node *right, int bf, Node *node,int lineNo);
#endif // _NODEVERIFIER_H
