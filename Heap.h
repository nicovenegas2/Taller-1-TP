#include <iostream>
#include <math.h>
#include "Node.h"
using namespace std;

/*
clase heap que contiene una lista de nodos
y los ordena de menor a mayor dependiendo de su atributo value
*/    
class Heap {
public:
    Heap(int size);
    ~Heap();
    int isEmpty();
    void insert(Node *node);
    Node* pull();
    int peek();
    int getSize();
    void print();
    void clear();
private:
    Node *arr;
    int size;
    int count;
    void swap(int i, int j);
    void bubbleUp();
    void bubbleDown();
};
