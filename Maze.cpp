#include "Maze.h"
#include <iostream>
#include <ctime>
using namespace std;

// contruimos un laberinto y lo generamos
Maze::Maze(int dim, int p) {
    srand(time(NULL)); // set seed for random number generator
    Maze::dim = dim;
    Maze::void_percentage=p;
    Maze::visited = new Container(dim);
    Maze::porVisitar = new Heap(pow(dim, 2));
    Maze::finished = false;
    Maze::generate();
}

Maze::~Maze() {
    for (int i = 0; i < dim; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}


// generamos el laberinto
void Maze::generate() {
    Maze:: clearPorVisitar();  //
    Maze:: clearVisited();     //limpiamos los contenedores por una posible reutilizacion
    Maze:: finished = false;
    Maze::arr = new int*[dim];
    for (int i = 0; i < dim; i++) {
        Maze::arr[i] = new int[dim];         // rellenamos el array con numeros aleatorios
        for (int j = 0; j < dim; j++) {
            Maze::arr[i][j] = rand() % 100 < void_percentage ? EMPTY : WALL;
        }
    }

    // set the entrance and exit
    
    Maze::arr[0][0] = IN_DOOR;
    Maze::arr[dim-1][dim-1] = OUT_DOOR;
}



// impresion del laberinto
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
                
                case SOLVED:
                    cout << "\033[1;31m@\033[0m";
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

float Maze::distance(int x, int y, int x2, int y2) {
    return sqrt(pow(x-x2, 2) + pow(y-y2, 2));
}


// resolucion de laberinto
void Maze::solve(bool show){
    // set the entrance
    Node *root = new Node(0, 0, 0," ", NULL);
    Node *current = root;
    visit(current);         
    if (!Maze::closeOut())
    {
        while(!porVisitar->isEmpty() && !finished){
        current = porVisitar->pull();
        visit(current);
        }
    }
    
    if(!finished){
        cout << "Sin solucion" << endl;
    }else {
        cout << "Solucion encontrada" << endl;
        cout << "Camino de solucion: " << current->getPath() << endl;
        if(show){
            Maze::markSolved(current);
            Maze::print();
        }
        
    }
}


// visitamos un nodo para agregar sus posibles movimientos a los contenedores
void Maze::visit(Node *nodeVisit){
    int x = nodeVisit->get_i();
    int y = nodeVisit->get_j();
    // cout << "Visited: " << x << " " << y << endl;
    if (arr[x][y] == OUT_DOOR) {
        finished = true;
        return;
    }
    else if ((arr[x][y] == EMPTY || arr[x][y] == IN_DOOR)){ 
        visited->mark(x, y);
        // visit all the neighbors
        if (x > 0 && (arr[x-1][y] == EMPTY || arr[x-1][y] ==OUT_DOOR) && !visited->isMarked(x-1, y)) { //chequeamos abajo
            Node *node = new Node(x-1, y, distance(x-1, y, dim-1, dim-1),"N", nodeVisit);
            porVisitar->insert(node);
            visited->mark(x-1, y);
            // cout << "Inserted: " << x-1 << " " << y << endl;
        }
        if (x < dim-1 && (arr[x+1][y] == EMPTY || arr[x+1][y] == OUT_DOOR) && !visited->isMarked(x+1, y)) { // chequeamos arriba
            Node *node = new Node(x+1, y, distance(x+1, y, dim-1, dim-1),"S", nodeVisit);
            porVisitar->insert(node);
            visited->mark(x+1, y);
            // cout << "Inserted: " << x+1 << " " << y << endl;
        }
        if (y > 0 && (arr[x][y-1] == EMPTY || arr[x][y-1] == OUT_DOOR )&& !visited->isMarked(x, y-1)) { // chequeamos izquierda
            Node *node = new Node(x, y-1, distance(x, y-1, dim-1, dim-1),"W", nodeVisit);
            porVisitar->insert(node);
            visited->mark(x, y-1);
            // cout << "Inserted: " << x << " " << y-1 << endl;
        }
        if (y < dim-1 && (arr[x][y+1] == EMPTY || arr[x][y+1] == OUT_DOOR) && !visited->isMarked(x, y+1)) { // chequeamos derecha
            Node *node = new Node(x, y+1, distance(x, y+1, dim-1, dim-1),"E", nodeVisit);
            porVisitar->insert(node);
            visited->mark(x, y+1);
            // cout << "Inserted: " << x << " " << y+1 << endl;
        }
    }
}


// hacemos el camino de vuelta para poder imprimirlo en rojo
void Maze::markSolved(Node *node){
    int x,y;
    Node *current = node;
    while(current != NULL){
        x = current->get_i();
        y = current->get_j();
        arr[x][y] = SOLVED;
        current = current->getPrevious();
    }
}


void Maze::clearPorVisitar(){
    porVisitar->clear();
}
                                    // limpiamos contenedores
void Maze::clearVisited(){
    visited->clear();
}


// chequeamos si el laberinto esta cerrado por defecto
bool Maze::closeOut(){
    if(arr[dim-2][dim-1] == WALL && arr[dim-1][dim-2] == WALL){
        return true;
    }

    return false;
}