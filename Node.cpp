#include "Node.h"

Node::Node(long long buf)
{
    capacity = 0;
    buffer = buf;
}

Node::~Node(void)
{
    capacity = 0;
    buffer = 0;
}