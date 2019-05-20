#pragma once
#include "Graph.hpp"
struct Commodity{
    int sourceNode;
    int sinkNode;
    int flow;
};

class MCFSolver{
public:

private:
    std::vector <Commodity> commodityVector;
};