#pragma once

#include <memory>
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
    void calculateGreedy();
    void generatePossiblePaths(int sourceNode, int sinkNode);
    void generatePossiblePathsUtil(int sourceNode, int sinkNode, bool visited[],
                                                             int path[], int & pathIndex);
private:
    std::vector <Commodity> commodityVector;
    Graph graphToSolve;
};