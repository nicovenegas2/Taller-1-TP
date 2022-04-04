#include "Heap.h"
#include <random>
#include "Node.h"
using namespace std;
int main(){
    cout << "---------- Starting Test Heap -----------" << endl;
    //Heap h();
    Node* n1 = new Node(1,2,3,"",NULL);
    int x,y;
    cout <<"inserting numbers" << endl;
    for (int i = 0; i < 20; i++) {
        x = lrand48() % 10;
        y = lrand48() % 10;
        cout << "inserting: " << x << "," << y << endl;
       // h->insert(n1);
    }

}