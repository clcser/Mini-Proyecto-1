#include "Node.h"
#include "SummaryNode.h"

SummaryNode::SummaryNode(long long buf, Node *l, Node *r) : Node(buf, nullptr)
{
    capacity = l->capacity + r->capacity;
    buffer = l->capacity + r->capacity;
    left = l;
    right = r;

    l->parent = this;
    r->parent = this;
}

SummaryNode::~SummaryNode(void)
{
    if (left != nullptr)
        delete left;

    if (right != nullptr)
        delete right;
}
