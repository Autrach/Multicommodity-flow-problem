#include "MCFSolver.hpp"


MCFSolver::MCFSolver(){
    /*for(int i = 0; i<6; i++){
        graphToSolve.addNode();
    }
    graphToSolve.insertArc(0,2, 4, 4);
    graphToSolve.insertArc(0,5, 3, 2);
    

    graphToSolve.insertArc(1,0, 7, 3);
    graphToSolve.insertArc(1,2, 1, 2);

    graphToSolve.insertArc(2,4, 4, 6);
    graphToSolve.insertArc(2,5, 4, 5);

    graphToSolve.insertArc(3,2, 2, 2);

    graphToSolve.insertArc(4,3, 5, 1);
    
    graphToSolve.insertArc(5,4, 2, 4);
    graphToSolve.insertArc(5,1, 7, 5);*/
    
    /*
    for(int i = 0; i<5; i++){
        graphToSolve.addNode();
    }

    graphToSolve.insertArc(0,2, 6, 5);
    graphToSolve.insertArc(0,1, 10, 3);
    graphToSolve.insertArc(1,2, 15, 1);
    graphToSolve.insertArc(1,3, 5, 8);
    graphToSolve.insertArc(2,3, 10, 2);
    graphToSolve.insertArc(2,4, 5, 2);
    graphToSolve.insertArc(3,4, 8, 4);
   */

    for(int i = 0; i<6; i++){
        graphToSolve.addNode();
    }
    graphToSolve.insertArc(0,1, 7, 3);
    graphToSolve.insertArc(0,2, 4, 4);
    graphToSolve.insertArc(1,2, 6, 5);
    graphToSolve.insertArc(1,3, 6, 5);
    graphToSolve.insertArc(2,4, 8, 8);
    graphToSolve.insertArc(2,3, 5, 9);
    graphToSolve.insertArc(3,4, 20, 7);
    graphToSolve.insertArc(3,5, 7, 2);
    graphToSolve.insertArc(4,3, 10, 6);
    graphToSolve.insertArc(4,5, 10, 9);
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
    std::vector<int> result;
    for(int i = 0; i<commodityVector.size(); i++){
        std::cout << "Składnia numer " << i << std::endl;
        int sum=0;
        while(true){
            std::vector <std::vector<int>> pathsVector = generatePossiblePaths(commodityVector[i].sourceNode, commodityVector[i].sinkNode);
            if(pathsVector.size()== 0){
                std::cout << "brak dróg " << std::endl;
                break;
            }

            std::pair <int,int> posCostPath = getCheapestPath(pathsVector);
            float currentFlow = usePath(pathsVector[posCostPath.first], commodityVector[i].flow);
            std::cout<<currentFlow <<std::endl;
            sum += posCostPath.second *currentFlow;
            if(currentFlow == commodityVector[i].flow){
                commodityVector[i].flow =0;
                break;
            }
            commodityVector[i].flow -= currentFlow;
            
            std::cout<<"obecny flow: "<<  currentFlow << " commodity flow: " << commodityVector[i].flow << std::endl;
        }
        result.push_back(sum);
    }
    std::cout << "Podsumowanie: "<< std::endl;

    for(int i = 0 ; i<result.size(); i++ ){
        std::cout << i << " składnia koszt: " << result[i];
        if(commodityVector[i].flow> 0){
            std::cout << " brakujący przepływ: " << commodityVector[i].flow;
        }
        std::cout << std::endl;
    }
     
}

std::vector <std::vector<int>> MCFSolver::generatePossiblePaths(int sourceNode, int sinkNode){
    std::vector <std::vector<int>> pathsVector;
    int nodesCount = graphToSolve.getNodeCount();
    bool *visited = new bool[nodesCount]; 
    int *path = new int[nodesCount];
    int pathIndex = 0;
    for (int i = 0; i < nodesCount; i++){
        visited[i] = false; 
    }
    generatePossiblePathsUtil(sourceNode, sinkNode, visited, path, pathIndex, pathsVector);

    for ( const std::vector<int> &v : pathsVector )
    {
        for ( const auto  &x : v ) {
            std::cout << x << ' ';
        }
        std::cout << std::endl;
    }

	return pathsVector;

}


void MCFSolver::generatePossiblePathsUtil(int sourceNode, int sinkNode, bool visited[],
                                                                     int path[], int & pathIndex, std::vector <std::vector<int>> &pathsVector){
    //std::cout << sourceNode<< std::endl;
    std::vector <Arc> arcVector = graphToSolve.getArcVector();
    path[pathIndex] = sourceNode;
    visited[sourceNode] = true;
    pathIndex++;
    
    if(sourceNode == sinkNode){
        std::vector <int> pathRow;
        for(int i = 0; i<pathIndex; i++){
            pathRow.push_back(path[i]);
        }
        pathsVector.push_back(pathRow);
        std::cout << std::endl;
    }
    else{
        
        for(int i = 0; i<arcVector.size(); i++ ){
            if(!visited[arcVector[i].sinkNode] && arcVector[i].sourceNode == sourceNode){
                generatePossiblePathsUtil(arcVector[i].sinkNode, sinkNode, visited, path, pathIndex, pathsVector);
            }
        }
    }
    pathIndex--; 
    visited[sourceNode] = false; 
}
std::pair<int,int> MCFSolver::getCheapestPath(std::vector <std::vector<int>> pathsVector){
    int minPath=0;
    int pathIndex= 0;
    int i = 0;
    for ( const std::vector<int> &v : pathsVector )
    {
        int currentPath = 0;
        for ( int i = 0; i<v.size()-1; i++ ) {
            currentPath += graphToSolve.getArcCost(v[i], v[i+1]);
        }
        if(minPath== 0){
            minPath = currentPath;
        }
        if(minPath>currentPath){
            minPath = currentPath;
            pathIndex = i;
        }
        i++;
    }
    std::cout << minPath << "  " << pathIndex << std::endl;
    return std::make_pair(pathIndex, minPath);
}

float MCFSolver::usePath(std::vector <int> path, int flow){
    float minCapacity=0;
    int index= 0;
    for ( int i = 0; i<path.size()-1; i++ ) {
            if(minCapacity > graphToSolve.getArcCapacity(path[i], path[i+1]) || minCapacity== 0){
                minCapacity = graphToSolve.getArcCapacity(path[i], path[i+1]);
                index = i;
            }

        }
        if(minCapacity>=flow){
            minCapacity = flow;
        }else
        {
            graphToSolve.removeArc(path[index], path[index+1]);
        }
        
    for( int i = 0; i<path.size()-1; i++ ) {
        graphToSolve.reduceArcCapacity(path[i], path[i+1], minCapacity);
    }

    
    std::cout << minCapacity << std::endl;
    return minCapacity;
}