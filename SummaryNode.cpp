#include <iostream>
#include "SummaryNode.h"

SummaryNode::SummaryNode(long long buf, SummaryNode* left, SummaryNode* right) : Node(buf) 
{
    this->left = left;
    this->right = right;
        
    if(right == nullptr) {
        this->capacity = left->capacity;
        this->buffer = left->buffer;
    } 
    else {
        this->capacity = left->capacity + right->capacity;
        this->buffer = left->buffer + right->buffer;
    }
}

SummaryNode::SummaryNode(long long buf, ArrNode* left, ArrNode* right) : Node(buf) 
{
    this->left = left;
    this->right = right;
        
    if(right == nullptr) {
        this->capacity = left->capacity;
        this->buffer = left->buffer;
    } 
    else {
        this->capacity = left->capacity + right->capacity;
        this->buffer = left->buffer + right->buffer;
    }
}

SummaryNode::~SummaryNode() {

}