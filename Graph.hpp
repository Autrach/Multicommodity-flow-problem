#include <iostream>
#include <vector>
struct Arc{
    int sourceNode;
    int sinkNode;
    int capacity;
};


class Graph{
public:
    void insertArc(int sourceNode, int sinkNode, int capacity);
    void addNode(); 
    void printGraph();
private:
    int nodeCount = 0;
    std::vector <Arc> arcVector;
};

