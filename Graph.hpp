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
    int getArcCost(int sourceNode, int sinkNode);
    int getArcCapacity(int sourceNode, int sinkNode);
    void removeArc(int sourceNode, int sinkNode);
    void removeArc(int pos);
    std::vector <Arc> getArcVector();
    void reduceArcCapacity(int sourceNode, int sinkNode, int val);
private:
    int nodeCount = 0;
    std::vector <Arc> arcVector;
};

