#ifndef SUMMARYNODE_H
#define SUMMARYNODE_H

#include "ArrNode.h"

class SummaryNode : public Node
{
    public:
        void* left;
        void* right;
        void* up;

        SummaryNode(long long buf, SummaryNode* left, SummaryNode* right);
        SummaryNode(long long buf, ArrNode* left, ArrNode* right);
        ~SummaryNode();
};

#endif