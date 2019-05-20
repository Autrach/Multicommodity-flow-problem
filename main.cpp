#include "Graph.hpp"
#include "MCFSolver.hpp"
#include <iostream>

int main(){
    MCFSolver MCF;
    MCF.addCommodity(5,6, 2.2);
    MCF.printSolution();
}