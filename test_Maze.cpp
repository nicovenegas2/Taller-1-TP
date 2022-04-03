#include "Maze.h"
#include <time.h>
#include <ctime>
using namespace std;


int main(){

    unsigned t1, t2, t3;
    t3 = 0;
    Maze m(1000, 80);
    int i;
    for (i = 0; i < 100; i++){
        m.generate();
        // m.print();
        t1 = clock();
        m.solve();
        
        t2 = clock();
        cout << "Time: " << (t2 - t1) / (double)CLOCKS_PER_SEC << endl;
        t3 += (t2 - t1);
    }
    cout <<"Total laberinths: "<< i << " Total time: " << t3 / (double)CLOCKS_PER_SEC << endl;
    cout << "Average time: " << t3 / (double)CLOCKS_PER_SEC / i << endl;

    return 0;
}




// int main() {
//     time_t t, t2;
//     t = time(NULL);
//     Maze m(1000, 80);
//     m.print();
//     m.solve();
//     t2 = time(NULL);
//     cout << "Tiempo: " << t2 - t << " segundos" << endl;
//     return 0;

// }