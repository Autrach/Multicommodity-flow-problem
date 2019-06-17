#include "Graph.hpp"
#include "MCFSolver.hpp"
#include <iostream>

int main(){
    MCFSolver MCF;
    /* MCF.addCommodity(0,3, 4);
    MCF.addCommodity(5,2, 2);*/

    //MCF.addCommodity(0,4,13);

    MCF.addCommodity(1,5, 9);
    MCF.addCommodity(0,3, 5);
    MCF.addCommodity(2,5,8);

    MCF.printSolution();
    MCF.calculateGreedy();
}