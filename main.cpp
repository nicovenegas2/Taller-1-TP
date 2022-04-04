#include "Maze.h"
#include <iostream>
#include <ctime>

int main(){

    unsigned t1, t2, t3;
    int dim = 1000;
    t3 = 0;
    Maze m(dim, 90);
    int i;
    for (i = 0; i < 100; i++){
        m.generate();
        // m.print();
        t1 = clock();
        m.solve(false);
        
        t2 = clock();
        cout << "Time: " << (t2 - t1) / (double)CLOCKS_PER_SEC << endl;
        t3 += (t2 - t1);
    }
    cout << endl << endl;
    cout << "Dimesion: " << dim << "x" << dim << endl;
    cout <<"Total laberinths: "<< i <<endl;
    cout << "Total time of solutions: " << t3 / (double)CLOCKS_PER_SEC << "[s]"<< endl;
    cout << "Average time: " << t3 / (double)CLOCKS_PER_SEC / i << "[s]" << endl;

    return 0;
}
