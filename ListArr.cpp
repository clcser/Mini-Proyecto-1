#include <iostream>
#include <math.h>
#include "ListArr.h"

ListArr::ListArr(long long buf) {
    first = new ArrNode(buf, nullptr);
    root = new SummaryNode(buf, first, nullptr);
    nodes = 1;
}

ListArr::~ListArr() {

}

int ListArr::size() {

}

void ListArr::insert(int data, int index) {

}

void ListArr::insert_left(int data) { // inserta en el indice 0
    
    first->insert(data,0);
    /*
    if(first->buffer < first->buffer) {
        for(int i = first->buffer; i>0; i--) {
            first->arr[i+1] = first->arr[i];
        }
        first->arr[0] = data;
    }
    else {
        ArrNode* node = new ArrNode(first->buffer, first);
        node->arr[0] = data;
        first = node;
    }
    */
    // ACTUALIZAR ARBOL
}

void ListArr::insert_right(int data) { // baja por el arbol e inserta en el indice n-1
    ArrNode* node;
    int i;
    node = binarySearch(root->buffer, &i);
    node->insert(data,i);

    // ACTUALIZAR ARBOL
}

void ListArr::print() {

}

bool ListArr::find(int data) {

}

void ListArr::createTree(ArrNode* first) { // siempre sera un arbol completo
    ArrNode* node = first;
    int leaves = 1<<(int)ceil(log(nodes)/log(2));
    
    for(int i = 1; i<=leaves; i++) {

    }
}

ArrNode* ListArr::binarySearch(long long index, int* subIndex) {
    
}