#include "Maze.h"
using namespace std;
int main() {
    Maze m(20, 60);
    m.print();
    m.solve();
    return 0;

}