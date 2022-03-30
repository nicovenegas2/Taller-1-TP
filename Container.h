#include <iostream>

class Container
{
private:
    int **arr;
    int size;
public:
    Container(int size);
    ~Container();
    int getSize();
    void mark(int i, int j);
    void unmark(int i, int j);
    bool isMarked(int i, int j);
};
