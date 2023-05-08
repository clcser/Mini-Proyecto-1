#include "Node.h"
#include "SummaryNode.h"

SummaryNode::SummaryNode(Node *l, Node *r) : Node(0, 0)
{
    left = l;
    right = r;

    if (l != nullptr) {
        capacity += l->capacity;
        buffer += l->buffer;
        l->parent = this;
    }

    if (r != nullptr) {
        capacity += r->capacity;
        buffer += r->buffer;
        r->parent = this;
    }
}

SummaryNode::~SummaryNode(void)
{
    if (left != nullptr)
        delete left;

    if (right != nullptr)
        delete right;
}
