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
    bool shouldBuild = false;
    head->insert(v, 0, shouldBuild);

    if (shouldBuild)
        build();
    else
        propagate(head);
}

void ListArr::insert_right(int v)
{
    bool shouldBuild = false;
    tail->insert(v, tail->capacity, shouldBuild);

    if (shouldBuild) {
        tail = tail->next;
        build();
    } else {
        propagate(tail);
    }
}

void ListArr::insert(int v, long long i)
{
    ArrNode* node;
    long long index;
    bool shouldBuild = false;
    node = binarySearch(i, index);
    node->insert(v, index, shouldBuild);

    if (shouldBuild)
        build();
    else
        propagate(node);
}

void ListArr::print(void)
{
    ArrNode *u = head;
    long long i, j;

    j = 0;
    while (u != nullptr) {
        std::cout << "Node " << ++j << ": ";

        for (i = 0; i < u->capacity; i++)
            std::cout << u->get(i) << " ";

        std::cout << std::endl;

        u = u->next;
    }
}

bool ListArr::find(int v)
{
    ArrNode *u = head;

    while (u != nullptr) {
        for (int i = 0; i < u->capacity; i++)
            if (u->get(i) == v)
                return true;

        u = u->next;
    }

    return false;
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

    while (prevLevel.size() != 1) {
        for (i = 0; i < prevLevel.size(); i += 2) {
            if (i != prevLevel.size() - 1)
                currLevel.push_back(new SummaryNode(prevLevel[i], prevLevel[i + 1]));
            else
                currLevel.push_back(prevLevel[i]);
        }

        prevLevel = currLevel;
        currLevel.clear();
    }

    root = (SummaryNode *) prevLevel[0];

    prevLevel.clear();
    currLevel.clear();
}

void ListArr::propagate(Node *u)
{
    u = u->parent;

    while (u != nullptr) {
        (u->capacity)++;
        u = u->parent;
    }
}

ArrNode *ListArr::binarySearch(long long index, long long &subIndex) 
{
    try {
        if(index < 0 || index > root->buffer) {
            throw "Out of bounds.";
        }

        SummaryNode* node = root;
        while(index > head->buffer) {
            if(index <= node->left->capacity) {
                node = (SummaryNode *) node->left;
            }
            else {
                index -= node->left->capacity;
                node = (SummaryNode *) node->right;
            }
        }
        if(index <= node->left->capacity) {
            subIndex = index;
            return (ArrNode *) node->left;
        }
        else {
            index -= node->left->capacity;
            subIndex = index;
            return (ArrNode *) node->left;
        }
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        exit(EXIT_FAILURE);
    }
}
