#ifndef LISTARR_H
#define LISTARR_H

#include "ArrNode.h"
#include "SummaryNode.h"

class ListArr
{
    private:
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
        bool find(int v);
        void build(void);
        ArrNode* binarySearch(long long index, int* subIndex);
};

#endif
