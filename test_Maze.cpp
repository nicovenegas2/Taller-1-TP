#include "Maze.h"
using namespace std;
int main() {
    Maze m(40, 80);
    m.print();
    m.solve();
    return 0;

}