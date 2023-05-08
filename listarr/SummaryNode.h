#ifndef SUMMARYNODE_H
#define SUMMARYNODE_H

#include "Node.h"

class SummaryNode : public Node
{
    public:
        Node *left;
        Node *right;

        SummaryNode(Node *l, Node *r);
        ~SummaryNode(void);
        void remove(Node *u);
};

#endif
