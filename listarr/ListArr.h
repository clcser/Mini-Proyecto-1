#ifndef LISTARR_H
#define LISTARR_H

#include "ArrNode.h"
#include "SummaryNode.h"

class ListArr
{
    private:
        long long buffer;
        ArrNode *head;
        ArrNode *tail;
        SummaryNode *root;

    public:
        ListArr(long long b);
        ~ListArr(void);
        long long size(void);
        void insert_left(int v);
        void insert_right(int v);
        void insert(int v, long long i);
        void print(void);
        bool find(int v); // linear search by element value lookup
        void build(void); // build tree and assign root to root
        void propagate(Node *u); // increase capacity by 1 from a list node all the way to the root
        ArrNode *binarySearch(long long index, long long &subIndex); // find node that contains index
};

#endif
