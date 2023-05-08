#ifndef ARRNODE_H
#define ARRNODE_H

#include "Node.h"

class ArrNode : public Node
{
    private:
        int *data;

    public:
        ArrNode *next;

        ArrNode(long long buf, ArrNode *n);
        ~ArrNode(void);
        void set(int v, long long i);
        int get(long long i);
        void insert(int v, long long i, bool &shouldBuild);
        bool full(void);
};

#endif
