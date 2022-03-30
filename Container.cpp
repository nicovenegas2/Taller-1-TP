#include "Container.h"


Container::Container(int size) {
    size = size;
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

void Container::mark(int i, int j) {
    if (i < 0 || i >= size || j < 0 || j >= size) {
        return;
    }
    arr[i][j] = 1;
}

void Container::unmark(int i, int j) {
    if (i < 0 || i >= size || j < 0 || j >= size) {
        return;
    }
    arr[i][j] = 0;
}

bool Container::isMarked(int i, int j) {
    if (i < 0 || i >= size || j < 0 || j >= size) {
        return false;
    }
    return arr[i][j] == 1;
}
