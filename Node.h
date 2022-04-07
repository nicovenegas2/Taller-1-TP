#include <iostream>

using namespace std;

/*
clase Nodo que contiene una posicion x,y
un valor y una referencia al nodo padre
*/    
class Node {
public:
    Node();
    ~Node();
    Node(Node* node);
    Node(int i, int j, int value, string path, Node* previous);

    // NOT best practice to have a getter for the private member!
    int get_i();
    int get_j();
    Node *getPrevious();
    int getValue();
    int getDepth();
    
    // NOT best practice to have a getter for the private member!
    void setPrevious(Node *previous);
    void setDepth(int depth);
    
    // main methods
    int isRoot();
    string getPath();
    void print();

private:
    // particular variables of this problem
    int i; // row
    int j; // column
    int value; // a value representing a cost for choosing this node
    int depth; // the depth of this node in the tree
    string path; // the path from root to this node
    // structural variables: meaning relationships between nodes
    Node *previous; // the previous node in the path
};  // end class Node

