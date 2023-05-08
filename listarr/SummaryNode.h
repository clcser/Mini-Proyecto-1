#ifndef SUMMARYNODE_H
#define SUMMARYNODE_H

#include "Node.h"

class SummaryNode : public Node
{
    public:
        Node *left;
        Node *right;

        SummaryNode(long long buf, Node *l, Node *r);
        ~SummaryNode(void);
};

#endif
