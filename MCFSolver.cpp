#include "MCFSolver.hpp"


MCFSolver::MCFSolver(){
    for(int i = 0; i<10; i++){
        graphToSolve.addNode();
    }
    graphToSolve.insertArc(0,9,5, 2.5);
    graphToSolve.insertArc(1,8,5, 2.7);
    

    graphToSolve.insertArc(3,4,5, 2.7);
    
    graphToSolve.insertArc(4,6,5, 2.7);
    graphToSolve.insertArc(4,5,5, 2.7);
    graphToSolve.insertArc(5,6,5, 2.7);

    graphToSolve.insertArc(3,6,5, 2.7);
    
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
void MCFSolver::calculateGreedy(){
    for(int i = 0; i<commodityVector.size(); i++){
        generatePossiblePaths(commodityVector[i].sourceNode, commodityVector[i].sinkNode);
    }
     
}

void MCFSolver::generatePossiblePaths(int sourceNode, int sinkNode){
    int nodesCount = graphToSolve.getNodeCount();
    bool *visited = new bool[nodesCount]; 
    int *path = new int[nodesCount];
    int pathIndex = 0;
    for (int i = 0; i < nodesCount; i++){
        visited[i] = false; 
    }
    generatePossiblePathsUtil(sourceNode, sinkNode, visited, path, pathIndex);
}


void MCFSolver::generatePossiblePathsUtil(int sourceNode, int sinkNode, bool visited[],
                                                                     int path[], int & pathIndex){
    std::cout << sourceNode<< std::endl;
    std::vector <Arc> arcVector = graphToSolve.getArcVector();
    path[pathIndex] = sourceNode;
    visited[sourceNode] = true;
    pathIndex++;
    
    if(sourceNode == sinkNode){
        std::cout<< "znaleziono: " << std::endl;
        for(int i = 0; i<pathIndex; i++){
            std::cout << path[i]<< "->";
        }
        std::cout << std::endl;
    }
    else{
        
        for(int i = 0; i<arcVector.size(); i++ ){
            //std::cout << i << "   " << visited [i] << arcVector[i].sourceNode << "->" <<  arcVector[i].sinkNode << "   " << arcVector.size() <<  std::endl;
            if(!visited[arcVector[i].sinkNode] && arcVector[i].sourceNode == sourceNode){
                generatePossiblePathsUtil(arcVector[i].sinkNode, sinkNode, visited, path, pathIndex);
            }
        }
    }
    pathIndex--; 
    visited[sourceNode] = false; 
    //std::cout << "path index: " << pathIndex << std::endl;
}