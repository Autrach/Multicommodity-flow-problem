#include "Graph.hpp"

void Graph::addNode(){
    nodeCount++;
}

void Graph::insertArc(int sourceNode, int sinkNode, int capacity, float cost){
    if(checkIfArcCanBeInserted(sourceNode, sinkNode, capacity, cost)){
        arcVector.push_back({sourceNode, sinkNode, capacity, cost});
    }
}

void Graph::printGraph(){
    std::cout << "Graf posiada : " << nodeCount << " wierzchołków" << std::endl;
    std::cout << "Łuki: " << std::endl;
    for(auto const& arc: arcVector){
        std::cout << arc.sourceNode << "->" << arc.sinkNode << " pojemność: " << arc.capacity << " koszt: " << arc.cost << std::endl;
    }
}
bool Graph::checkIfArcCanBeInserted(int sourceNode, int sinkNode, int capacity, float cost){
    if(sourceNode >= nodeCount || sinkNode >= nodeCount || sourceNode == sinkNode){
        std::cout << "błąd przy dodawaniu łuku" << std::endl;
        return false;
    }
    for(int i = 0; i < arcVector.size(); i++){
        if(arcVector[i].sourceNode == sourceNode && arcVector[i].sinkNode == sinkNode){
                std::cout << "podany łuk już istnieje" << std::endl;
                return false;
        }
    }
    return true;
}
int Graph::getNodeCount(){
    return nodeCount;
}
std::vector <Arc> Graph::getArcVector(){
    return arcVector;
}