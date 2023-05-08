#include "Node.h"

Node::Node(long long buf, Node *p)
{
    capacity = 0;
    buffer = buf;
    parent = p;
}

Node::~Node(void)
{
    capacity = 0;
    buffer = 0;
    parent = nullptr;
}
