#include "Maze.h"
#include <time.h>
#include <ctime>
using namespace std;



 int main() {
    cout << "-------------- Start test Maze --------------" << endl;
    Maze m(30, 90);
    m.print();
    m.solve(true);
    return 0;

 }