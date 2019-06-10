#pragma once
#include <iostream>
#include <vector>
struct Arc{
    int sourceNode;
    int sinkNode;
    int capacity;
    float cost;
};


class Graph{
public:
    void insertArc(int sourceNode, int sinkNode, int capacity, float cost);
    void addNode(); 
    void printGraph();
    bool checkIfArcCanBeInserted(int sourceNode, int sinkNode, int capacity, float cost);
    int getNodeCount();
    std::vector <Arc> getArcVector();
private:
    int nodeCount = 0;
    std::vector <Arc> arcVector;
};

