#include "Maze.h"
#include <iostream>

Maze::Maze(int dim, int p) {
    srand(time(NULL)); // set seed for random number generator
    Maze::dim = dim;
    Maze::void_percentage=p;
    Maze::generate();
    Maze::visited = new Container(dim);
    Maze::porVisitar = new Heap(dim);
    Maze::finished = false;
}

Maze::~Maze() {
    for (int i = 0; i < dim; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void Maze::generate() {
    arr = new int*[dim];
    for (int i = 0; i < dim; i++) {
        arr[i] = new int[dim];
        for (int j = 0; j < dim; j++) {
            arr[i][j] = rand() % 100 < void_percentage ? EMPTY : WALL;
        }
    }

    // set the entrance and exit
    
    arr[0][0] = IN_DOOR;
    arr[dim-1][dim-1] = OUT_DOOR;
}

void Maze::print() {
    for (int i = 0; i < Maze::dim; i++) {
        for (int j = 0; j < Maze::dim; j++) {
            //cout << arr[i][j] << " ";
            switch (arr[i][j]) {
                case IN_DOOR:
                    cout << "I";
                    break;
                case OUT_DOOR:
                    cout << "O";
                    break;

                case WALL:
                    cout << "#";
                    break;
                default:
                    cout << " ";
                    break;
            }
            cout << " "; 
        }
        cout << endl;
    }
}

float Maze::distance(int x, int y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}

void Maze::solve(){
    // set the entrance
    Node *root = new Node(0, 0, 0, NULL);
    Node *current = root;

    while(!porVisitar->isEmpty() || finished){

    }
}

void Maze::visit(Node *nodeVisit){
    int x = nodeVisit->get_i();
    int y = nodeVisit->get_j();
    if (arr[x][y] == OUT_DOOR) {
        finished = true;
        return;
    }
    else if (arr[x][y] == EMPTY){
        visited->mark(x, y);
        // visit all the neighbors
        if (x > 0 && arr[x-1][y] == EMPTY && !visited->isMarked(x-1, y)) {
            Node *node = new Node(x-1, y, distance(x-1, y), node);
            porVisitar->insert(node);
        }
        if (x < dim-1 && arr[x+1][y] == EMPTY && !visited->isMarked(x-1, y)) {
            Node *node = new Node(x+1, y, distance(x+1, y), node);
            porVisitar->insert(node);
        }
        if (y > 0 && arr[x][y-1] == EMPTY && !visited->isMarked(x-1, y)) {
            Node *node = new Node(x, y-1, distance(x, y-1), node);
            porVisitar->insert(node);
        }
        if (y < dim-1 && arr[x][y+1] == EMPTY && !visited->isMarked(x-1, y)) {
            Node *node = new Node(x, y+1, distance(x, y+1), node);
             porVisitar->insert(node);
        }
    }
}