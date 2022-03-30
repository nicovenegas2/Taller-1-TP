#include "Maze.h"
#include <iostream>

Maze::Maze(int dim, int p) {
    srand(time(NULL)); // set seed for random number generator
    Maze::dim = dim;
    Maze::void_percentage=p;
    Maze::generate();
    Maze::visited = new Container(dim);
    Maze::heap = new Heap(dim);
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
}