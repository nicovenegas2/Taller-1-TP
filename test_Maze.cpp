#include "Maze.h"
#include <time.h>
#include <ctime>
using namespace std;



 int main() {
     Maze m(100, 80);
     m.print();
     m.solve(true);
     return 0;

 }