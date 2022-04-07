#include "Node.h"
#include <iostream>
using namespace std;

int main(){
    cout << "-------------- Start test Node --------------" << endl;
    cout << "create nodes" << endl;
    Node *n1 = new Node(1,2,3,"1,2",NULL);
    Node *n2 = new Node(2,3,4,"2,3",n1);
    Node *n3 = new Node(3,4,5,"3,4",n2);
    Node *n4 = new Node(4,5,6,"4,5",n3);
    cout << "print nodes" << endl;
    n1->print();
    n2->print();
    n3->print();
    cout << "show path" << endl;
    cout << n4->getPath() << endl;
    
}