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
    std::vector <std::vector<int>> generatePossiblePaths(int sourceNode, int sinkNode);
    void generatePossiblePathsUtil(int sourceNode, int sinkNode, bool visited[],
                                                             int path[], int & pathIndex, std::vector <std::vector<int>> &pathsVector);
    std::pair <int,int> getCheapestPath(std::vector <std::vector<int>> pathsVector);
    float usePath(std::vector <int> path, int flow);
private:
    std::vector <Commodity> commodityVector;
    Graph graphToSolve;
};