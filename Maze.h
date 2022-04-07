#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Container.h"
#include "Heap.h"
using namespace std;


/*
clase Maze, genera un laberinto aleatorio
 donde es posible imprimirlo, resolverlo y volver a imprimirlo con el
 camino de salida en rojo
*/    

// best practice:
#define IN_DOOR 2
#define OUT_DOOR 3
#define WALL 1
#define EMPTY 0
#define SOLVED 4

class Maze {
public:
    Maze(int dim, int p);
    ~Maze();
    void print();
    void solve(bool show); // solve best path
    void generate(); // generate random maze
    float distance(int x, int y, int x2, int y2); // calculate distance between two points
    void visit(Node *node); // visit node
    void markSolved(Node *node); // mark node as solved
    void clearVisited(); // clear visited nodes
    void clearPorVisitar(); // clear por visitar nodes
    bool closeOut(); // close door
private:
    int dim; // dimension of maze
    int **arr; // array of ints
    int void_percentage; // percentage of void
    Container *visited; // contenedor de posiciones visitados
    Heap *porVisitar; // heap de posiciones por visitar
    bool finished; // finished solving
};