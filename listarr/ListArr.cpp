#include <iostream>
#include <vector>
#include "ListArr.h"
#include "ArrNode.h"
#include "SummaryNode.h"

ListArr::ListArr(long long b)
{
    head = new ArrNode(b, new ArrNode(b, nullptr));
    root = new SummaryNode(b, head, head->next);
}

ListArr::~ListArr(void)
{
    delete root;
}

long long ListArr::size(void)
{
    return root->capacity;
}

void ListArr::insert_left(int v)
{
}

void ListArr::insert_right(int v)
{
}

void ListArr::insert(int v, long long i)
{
}

void ListArr::print(void)
{
    ArrNode *v = head;
    long long i, j;

    j = 1;
    while (v != nullptr) {
        std::cout << "Node " << j << ": ";

        for (i = 0; i < v->capacity; i++)
            std::cout << v->get(i) << " ";

        std::cout << std::endl;

        v = v->next;
    }
}

bool ListArr::find(int v)
{
}

void ListArr::build(void)
{
    std::vector<Node *> prevLevel;
    std::vector<Node *> currLevel;
    ArrNode *v = head;
    long long i;

    while (v != nullptr) {
        prevLevel.push_back(v);
        v = v->next;
    }

    while (currLevel.size() != 1) {
        for (i = 0; i < prevLevel.size(); i += 2) {
            if (i != prevLevel.size() - 1)
                currLevel.push_back(new SummaryNode(v->buffer, prevLevel[i], prevLevel[i + 1]));
            else
                currLevel.push_back(prevLevel[i]);
        }

        prevLevel = currLevel;
        currLevel.clear();
    }

    root = (SummaryNode *) currLevel[0];

    prevLevel.clear();
    currLevel.clear();
}
