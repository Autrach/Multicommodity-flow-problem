#include "MCFSolver.hpp"

MCFSolver::MCFSolver(){
    for(int i = 0; i<10; i++){
        graphToSolve.addNode();
    }
    graphToSolve.insertArc(0,9,5, 2.5);
    graphToSolve.insertArc(1,8,5, 2.7);
    graphToSolve.insertArc(1,8,5, 2.7);
    graphToSolve.insertArc(10,10,5, 2.4);
}

void MCFSolver::addCommodity(int sourceNode, int sinkNode, float flow){
    if(checkIfCommodityCanBeAdded(sourceNode, sinkNode, flow)){
        commodityVector.push_back({sourceNode, sinkNode, flow});
    }
} 

bool MCFSolver::checkIfCommodityCanBeAdded(int sourceNode, int sinkNode, float flow){
    int nodeCount = graphToSolve.getNodeCount();
    if(sourceNode >= nodeCount || sinkNode >= nodeCount || sourceNode == sinkNode){
        std::cout << "błąd przy dodawaniu składni" << std::endl;
        return false;
    }
    for(int i = 0; i < commodityVector.size(); i++){
        if(commodityVector[i].sourceNode == sourceNode && commodityVector[i].sinkNode){
                std::cout << "podana składnia już istnieje" << std::endl;
                return false;
        }
    }
    return true;
} 

void MCFSolver::printSolution(){
    graphToSolve.printGraph();
    std::cout << "Składnie: " << std::endl;
    for(auto const& commodity: commodityVector){
        std::cout << commodity.sourceNode << "->" << commodity.sinkNode << " Przepływ: " << commodity.flow << std::endl;
    }
}