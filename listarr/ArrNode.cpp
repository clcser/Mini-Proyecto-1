#include <iostream>
#include "Node.h"
#include "ArrNode.h"

ArrNode::ArrNode(long long buf, ArrNode *n) : Node(buf, nullptr)
{
    data = new int[buf];
    next = n;
}

ArrNode::~ArrNode(void)
{
    delete data;

    // Since nodes are only deleted in ~ListArr, which deletes the whole tree,
    // it is not needed to delete the next node in the list.
    /*
    if (next != nullptr)
        delete next;
    */
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

// shouldBuild is a flag that indicates if ListArr tree should be rebuilt
void ArrNode::insert(int v, long long i, bool &shouldBuild)
{
    try {
        if (i < 0 or capacity < i)
            throw "Cannot insert: out of bounds.";

        // If there is no space, create new node and shift accordingly
        if (full()) {
            if (next == nullptr) {
                next = new ArrNode(buffer, nullptr);
                shouldBuild = true;
            } else if (next->full()) {
                next = new ArrNode(buffer, next);
                shouldBuild = true;
            }

            // Inserting at capacity requires no shifts since node is full
            if (i != capacity) {
                next->insert(data[buffer - 1], 0, shouldBuild);

                for (long long j = buffer - 1; j > i; j--)
                    data[j] = data[j - 1];

                data[i] = v;
            } else {
                next->insert(v, 0, shouldBuild);
            }
        } else {
            for (long long j = capacity; j > i; j--)
                data[j] = data[j - 1];

            data[i] = v;
            capacity++;
        }
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        exit(EXIT_FAILURE);
    }
}

bool ArrNode::full(void)
{
    return capacity == buffer;
}
