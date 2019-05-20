#include "Graph.hpp"

void Graph::addNode(){
    nodeCount++;
}

void Graph::insertArc(int sourceNode, int sinkNode, int capacity){
    if(sourceNode >= nodeCount || sinkNode >= nodeCount || sourceNode == sinkNode){
        std::cout << "błąd przy dodawaniu łuku" << std::endl;
        return;
    }
    for(int i = 0; i < arcVector.size(); i++){
        if(arcVector[i].sourceNode == sourceNode && arcVector[i].sinkNode){
                std::cout << "podany łuk już istnieje" << std::endl;
                return;
        }
    }
    arcVector.push_back({sourceNode, sinkNode, capacity});
}

void Graph::printGraph(){
    std::cout << "Graf posiada : " << nodeCount << " wierzchołków" << std::endl;
    std::cout << "Łuki: " << std::endl;
    for(auto const& arc: arcVector){
        std::cout << arc.sourceNode << "->" << arc.sinkNode << " pojemność: " << arc.capacity << std::endl;
    }
}