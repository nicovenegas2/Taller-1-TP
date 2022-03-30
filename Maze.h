#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Container.h"
#include "Heap.h"
using namespace std;

// best practice:
#define IN_DOOR 2
#define OUT_DOOR 3
#define WALL 1
#define EMPTY 0

class Maze {
public:
    Maze(int dim, int p);
    ~Maze();
    void print();
    void solve(); // solve best path
    void generate(); // generate random maze
    float distance(int x, int y); // calculate distance between two points
    void visit(Node *node); // visit node
private:
    int dim;
    int **arr;
    int void_percentage;
    Container *visited;
    Heap *porVisitar;
    bool finished;
};