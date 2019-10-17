//
// Created by Christian nahuel Rivera on 6/10/19.
//

#include "Segmentation.h"
#include "../entities/Graph.h"
#include "../entities/AdyacencyMatrixGraph.h"
#include "../entities/TreeGraph.h"
#include "../entities/KruskalKindOfGraph.h"
#include "KruskalAlgorithm.h"
#include "PrimAlgorithm.h"
#include "estructuras-auxiliares/ArrayDisjoinSet.h"
#include "estructuras-auxiliares/ArrayCompressedDisjoinSet.h"
#include <queue>

Segmentation::Segmentation(std::string mstAlgorithm) {
    assert(mstAlgorithm == "prim" || mstAlgorithm == "kruskal" || mstAlgorithm == "kruskal-compressed");

    this->mstStrategy = mstAlgorithm;

    if (mstAlgorithm == "prim") {
        this->mstAlgorithm = new PrimAlgorithm();
    } else if(mstAlgorithm == "kruskal") {
        this->mstAlgorithm = new KruskalAlgorithm(new ArrayDisjoinSet());
    }else{
        this->mstAlgorithm = new KruskalAlgorithm(new ArrayCompressedDisjoinSet());
    }
}

Graph* Segmentation::makeGraph(std::vector<std::pair<int, int>> *dots) {
    if(mstStrategy == "prim"){
        return new AdyacencyMatrixGraph(dots);
    }else{
        return new KruskalKindOfGraph(dots);
    }
}

Segmentation::~Segmentation() {
    delete mstAlgorithm;
}

std::vector<int> Segmentation::execute(std::vector<std::pair<int, int>> *dots, double depth, double sigmaT, double fT) {
    Graph *graph = makeGraph(dots);

    TreeGraph mst = *mstAlgorithm->makeMst(graph);

    std::vector<int> segments = std::vector<int>(dots->size(),1);
    int nextSegmentNumber = 2;

    for(Edge edge : mst.getEdges()){
        std::vector<Edge> *leftSubTree = getSubTree(edge.getFromVertex(), &mst, depth, edge.getToVertex());
        std::vector<Edge> *rigthSubTree = getSubTree(edge.getToVertex(), &mst, depth, edge.getFromVertex());

        if( isInconsistent(edge, leftSubTree, rigthSubTree, sigmaT, fT) ){
            mst.deleteEdge(edge);
            splitSegments(segments, mst, edge, nextSegmentNumber);
            nextSegmentNumber++;
        }
    }
    return segments;
}

std::vector<Edge> * Segmentation::getSubTree(int fromVertex, TreeGraph *graph, double depth, int excludeVertex) {
    auto *edges = new std::vector<Edge>();

    std::vector<bool> seen = std::vector<bool>(graph->getVertex(),false);
    seen.at(excludeVertex) = true;

    std::queue<int> vertexToVisit;
    vertexToVisit.push(fromVertex);

    int depthI = 0;
    int vertex;
    while( depthI < depth && !vertexToVisit.empty()){
        vertex = vertexToVisit.back(); vertexToVisit.pop();

        for(std::pair<int, long> edgeI : *graph->getAdyacents(vertex)){
            if( !seen.at(edgeI.first) ){
                edges->push_back(Edge(vertex,edgeI.first,edgeI.second));
                vertexToVisit.push(edgeI.first);
            }
        }
        seen.at(vertex) = true;
        depthI++; // este depthI está mal que se actualice en cada iteración. Tengo que encontrar otra forma de averiguar como resolver los niveles.
    }
    return edges;
}

bool
Segmentation::isInconsistent(Edge edge, std::vector<Edge> *leftSubTree, std::vector<Edge> *rigthSubTree, double sigmaT,
                             double fT) {
    return false;
}

void Segmentation::splitSegments(std::vector<int> segments, TreeGraph tree, Edge edge, int nextSegmentNumber){

}

