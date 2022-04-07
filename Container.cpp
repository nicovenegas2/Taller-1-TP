#include "Container.h"


// generamos un container de largo size
Container::Container(int size) {
    Container::size = size;
    arr = new int*[size];
    for (int i = 0; i < size; i++) {
        arr[i] = new int[size];
        for (int j = 0; j < size; j++) {
            arr[i][j] = 0;
        }
    }
}

Container::~Container() {
    for (int i = 0; i < size; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int Container::getSize() {
    return Container::size;
}


// marcamos una posicion en el container
void Container::mark(int i, int j) {
    if (i < 0 || i >= size || j < 0 || j >= size) {
        return;
    }
    arr[i][j] = 1;
}

// desmarcamos una posicion en el container
void Container::unmark(int i, int j) {
    if (i < 0 || i >= size || j < 0 || j >= size) {
        return;
    }
    arr[i][j] = 0;
}

// nos indica si una posicion esta ocupada o no
bool Container::isMarked(int i, int j) {
    if (i < 0 || i >= size || j < 0 || j >= size) {
        return false;
    }
    return arr[i][j] == 1;
}

// limpiamos el container desocupando todas las posiciones
void Container::clear(){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = 0;
        }
    }
}
