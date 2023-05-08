#include <iostream>
#include "Node.h"
#include "SummaryNode.h"

SummaryNode::SummaryNode(Node *l, Node *r) : Node(0, nullptr)
{
    left = l;
    right = r;

    // capacity and buffer should be the sum of their children's

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

void SummaryNode::remove(Node *u)
{
    try {
        if (u == nullptr)
            throw "Cannot remove: nullptr reference.";

        if (left == u)
            left = nullptr;
        else if (right == u)
            right = nullptr;
        else
            throw "Cannot remove: node is not children.";
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
    }
}
