#include <iostream>
#include "Node.h"
#include "ArrNode.h"

ArrNode::ArrNode(long long buf, ArrNode *n) : Node(buf)
{
    data = new int[buf];
    next = n;
}

ArrNode::~ArrNode(void)
{
    delete data;

    if (next != nullptr)
        delete next;
}

void ArrNode::set(int v, long long i)
{
    try {
        if (i < 0 or capacity <= i)
            throw "Cannot set: out of bounds.";

        data[i] = v;
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        exit(EXIT_FAILURE);
    }
}

int ArrNode::get(long long i)
{
    try {
        if (i < 0 or capacity <= i)
            throw "Cannot get: out of bounds.";

        return data[i];
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        exit(EXIT_FAILURE);
    }
}

void ArrNode::insert(int v, long long i)
{
    try {
        if (i < 0 or capacity < i)
            throw "Cannot insert: out of bounds.";

        if (full()) {
            if (next == nullptr)
                next = new ArrNode(buf, nullptr);
            else if (next->full)
                next = new ArrNode(buf, next);

            next->insert(data[buffer - 1], 0);

            for (long long j = buffer - 1; j > i; j--)
                data[j] = data[j - 1];
        } else {
            for (long long j = capacity; j > i; j--)
                data[j] = data[j - 1];

            capacity++;
        }

        data[i] = v;
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        exit(EXIT_FAILURE);
    }
}

bool ArrNode::full(void)
{
    return capacity == buffer;
}
