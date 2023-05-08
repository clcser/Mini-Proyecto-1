#include <iostream>
#include <vector>
#include "ListArr.h"
#include "ArrNode.h"
#include "SummaryNode.h"

ListArr::ListArr(long long b)
{
    tail = new ArrNode(b, nullptr);
    head = new ArrNode(b, tail);
    root = new SummaryNode(head, tail);
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
    head->insert(v, 0);
}

void ListArr::insert_right(int v)
{
    tail->insert(v, tail->capacity);

    if (tail->next != nullptr)
        tail = tail->next;
}

void ListArr::insert(int v, long long i)
{
}

void ListArr::print(void)
{
    ArrNode *u = head;
    long long i, j;

    j = 1;
    while (u != nullptr) {
        std::cout << "Node " << j << ": ";

        for (i = 0; i < u->capacity; i++)
            std::cout << u->get(i) << " ";

        std::cout << std::endl;

        u = u->next;
    }
}

bool ListArr::find(int v)
{
}

void ListArr::build(void)
{
    std::vector<Node *> prevLevel;
    std::vector<Node *> currLevel;
    ArrNode *u = head;
    long long i;

    while (u != nullptr) {
        prevLevel.push_back(u);
        u = u->next;
    }

    while (currLevel.size() != 1) {
        for (i = 0; i < prevLevel.size(); i += 2) {
            if (i != prevLevel.size() - 1)
                currLevel.push_back(new SummaryNode(prevLevel[i], prevLevel[i + 1]));
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

ArrNode *ListArr::binarySearch(long long index, int *subIndex) 
{
}
