#include "Container.h"
using namespace std;
int main(){
    Container c(10);
    int x,y;
    srand48(time(NULL));
    cout << "-------------- Start test Container --------------" << endl;
    for (int i = 0; i < 20; i++) {
        x = lrand48() % 10;
        y = lrand48() % 10;
        cout << "marking: " << x << "," << y << endl;
        c.mark(x,y);
    }
    for (int i = 0; i < 20; i++) {
        x = lrand48() % 10;
        y = lrand48() % 10;
        cout << "is marking: " << x << "," << y << "?: " << c.isMarked(x,y) <<  endl;
    }
    
}