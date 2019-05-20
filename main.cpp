#include "Graph.hpp"
#include <iostream>

int main(){
    Graph g;
    for(int i = 0; i<10; i++){
        g.addNode();
    }
    g.insertArc(0,9,5);
    g.insertArc(1,8,5);
    g.insertArc(1,8,5);
    g.insertArc(10,10,5);
    g.printGraph();
}