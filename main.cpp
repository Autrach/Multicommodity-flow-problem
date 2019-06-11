#include "Graph.hpp"
#include "MCFSolver.hpp"
#include <iostream>

int main(){
    MCFSolver MCF;
    MCF.addCommodity(0,3, 4);

    MCF.addCommodity(5,2, 2);
    MCF.printSolution();
    MCF.calculateGreedy();
}