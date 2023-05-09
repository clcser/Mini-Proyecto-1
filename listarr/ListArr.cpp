#include <iostream>
#include <vector>
#include "ListArr.h"
#include "ArrNode.h"
#include "SummaryNode.h"

ListArr::ListArr(long long b)
{
    try {
        if (b <= 0)
            throw "Invalid buffer size."

        buffer = b;
        tail = new ArrNode(b, nullptr);
        head = new ArrNode(b, tail);
        root = new SummaryNode(head, tail);
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
    }
}

ListArr::~ListArr(void)
{
    buffer = 0;
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
        tail = tail->next; // since tail has no next, and we should build, we must update reference
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
    if (head == nullptr)
        return;

    std::vector<Node *> prevLevel;
    std::vector<Node *> currLevel;
    ArrNode *u = head;
    long long i;

    while (u != nullptr) {
        prevLevel.push_back(u);

        // Unlink needed so that when old root is deleted,
        // ListArr data is not.
        if (u->parent != nullptr)
            ((SummaryNode *) (u->parent))->remove(u);
        u->orphan();

        u = u->next;
    }

    while (prevLevel.size() != 1) {
        for (i = 0; i < prevLevel.size() - (prevLevel.size() % 2); i += 2)
            currLevel.push_back(new SummaryNode(prevLevel[i], prevLevel[i + 1]));

        // if node has no partner combine with upper levels
        // this fixes issue for non complete binary trees
        if (prevLevel.size() % 2 == 1)
            currLevel.push_back(prevLevel[prevLevel.size() - 1]);

        prevLevel = currLevel;
        currLevel.clear();
    }

    if (root != nullptr)
        delete root;

    root = (SummaryNode *) prevLevel[0];
}

void ListArr::propagate(Node *u)
{
    u = u->parent;

    // traverse upwards updating capacity
    while (u != nullptr) {
        (u->capacity)++;
        u = u->parent;
    }
}

ArrNode *ListArr::binarySearch(long long index, long long &subIndex) 
{
    try {
        if(index < 0 || index > root->capacity)
            throw "Cannot search: out of bounds.";

        // exit condition is valid since only ArrNodes have buffer equal to the ListArr buffer
        SummaryNode *node = root;
        while (node->buffer != buffer) {
            if(index <= (node->left)->capacity) {
                node = (SummaryNode *) node->left;
            } else {
                index -= (node->left)->capacity;
                node = (SummaryNode *) node->right;
            }
        }

        subIndex = index;
        return (ArrNode *) node;
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        exit(EXIT_FAILURE);
    }
}
