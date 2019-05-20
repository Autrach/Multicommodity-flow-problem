#pragma once
#include "Graph.hpp"
struct Commodity{
    int sourceNode;
    int sinkNode;
    float flow;
};

class MCFSolver{
public:
    MCFSolver();
    void addCommodity(int sourceNode, int sinkNode, float flow);
    bool checkIfCommodityCanBeAdded(int sourceNode, int sinkNode, float flow);
    void printSolution();
private:
    std::vector <Commodity> commodityVector;
    Graph graphToSolve;
};