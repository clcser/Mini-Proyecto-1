#ifndef LISTARR_H
#define LISTARR_H

#include "ArrNode.h"
#include "SummaryNode.h"

class ListArr
{
    private:
        ArrNode *head;
        SummaryNode *root;

    public:
        ListArr(void);
        ~ListArr(void);
        long long size(void);
        void insert_left(int v);
        void insert_right(int v);
        void insert(int v, long long i);
        void print(void);
        bool find(int v);
};

#endif
