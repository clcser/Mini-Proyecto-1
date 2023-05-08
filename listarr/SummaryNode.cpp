#include "Node.h"
#include "SummaryNode.h"

SummaryNode::SummaryNode(Node *l, Node *r)
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
