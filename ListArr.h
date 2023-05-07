#include <iostream>

#ifndef ListArr_H
#define ListArr_H

// luego podemos separar esto en otro archivo
struct ArrNode { // nodo del listArray
    int* arr;
    int capacity;
    int used;
    ArrNode* next;
    
    ArrNode(int capacity) {
        this->capacity = capacity;
        this->used = 0;
        this->arr = new int[capacity];
    }
    
    ~ArrNode() {
        delete[] arr;
    }
};

// esto igual
struct SummaryNode { // nodo del arbolo resumen
    int capacity;
    int used;
    void* left;
    void* right;
    
    SummaryNode(SummaryNode* left, SummaryNode* right) { // constructor con hijos tipo nodo resumen
        this->left = left;
        this->right = right;
    }

    SummaryNode(ArrNode* left, ArrNode* right) { // constructor con hijos tipo nodo arrayList
        this->left = left;
        this->right = right;
    }

    ~SummaryNode() {
        
    }
};

class ListArr {
private:
    ArrNode* first; // puntero al primer nodo de la lista
    SummaryNode* root; // puntero a la raiz del arbol

public:
    ListArr();
    ~ListArr();
    int size(); // retorna cantidad de elementos almacenados
    void insert_left(int data); // inserta el valor data en el indice 0
    void insert_right(int data); // inserta el valor data en el indice size()-1
    void insert(int data, int i); // inserta el valor data en el indice i
    void print(); // imprime todos los valores almacenados
    bool find(int data); // busca si el valor data se encuentra almacenado
    void createTree(ArrNode* first); // crea el arbol de resumen, modifica el puntero a root del ArrList
};

#endif