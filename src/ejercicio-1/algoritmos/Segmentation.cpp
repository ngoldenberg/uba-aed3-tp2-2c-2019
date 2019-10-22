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
#include <assert.h>
#include <queue>
#include <stack>
#include <cmath>


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

std::vector<int> Segmentation::execute(std::vector<std::pair<int, int>> *dots, int depth, double sigmaT, double fT) {
    Graph *graph = makeGraph(dots);

    TreeGraph *mst = mstAlgorithm->makeMst(graph);

    std::vector<int> *segments = new std::vector<int>(dots->size(),1);
    int nextSegmentNumber = 2;

    for(Edge edge : mst->getEdges()){
        std::vector<Edge> *leftSubTree = getSubTree(edge.getFromVertex(), mst, depth, edge.getToVertex());
        std::vector<Edge> *rigthSubTree = getSubTree(edge.getToVertex(), mst, depth, edge.getFromVertex());

        if( isInconsistent(edge, leftSubTree, rigthSubTree, sigmaT, fT) ){
            mst->deleteEdge(edge);
            splitSegments(segments, mst, nextSegmentNumber, edge.getToVertex(), edge.getFromVertex());
            nextSegmentNumber++;
        }
        delete leftSubTree; delete rigthSubTree;
    }

    delete mst;

    return *segments;
}

std::vector<Edge> * Segmentation::getSubTree(int fromVertex, TreeGraph *graph, double depth, int excludeVertex) {
    auto *edges = new std::vector<Edge>();

    std::vector<bool> seen = std::vector<bool>(graph->getVertex(),false);
    seen.at(excludeVertex) = true;

    std::list<int> vertexToVisit = {fromVertex};
    for(int depthI = 0; depthI < depth; depthI++){
        std::list<int> nextVertexToVisit;
        for( auto vertex : vertexToVisit) {
            for (std::pair<int, long> edgeI : *graph->getAdyacents(vertex)) {
                if (!seen.at(edgeI.first)) {
                    edges->push_back(Edge(vertex, edgeI.first, edgeI.second));
                    nextVertexToVisit.push_back(edgeI.first);
                }
            }
            seen.at(vertex) = true;
        }
        vertexToVisit.clear(); vertexToVisit = nextVertexToVisit;
    }
    return edges;
}

bool
Segmentation::isInconsistent(Edge edge, std::vector<Edge> *leftSubTree, std::vector<Edge> *rigthSubTree, double sigmaT,
                             double fT) {
    double leftMean = mean(leftSubTree);
    double leftDesviation = desviation(leftSubTree, leftMean);
    double rightMean = mean(rigthSubTree);
    double rightDesviation = desviation(rigthSubTree, rightMean);
    Distancia W = edge.getWeight();

    return isInconsistent(leftMean,W,sigmaT*leftDesviation,fT) || isInconsistent(rightMean,W,sigmaT*rightDesviation,fT);


}

void Segmentation::splitSegments(std::vector<int> *segments, TreeGraph *forest, int nextSegmentNumber, int beginVertex,
                                 int excludeVertex) {

    std::list<int> *vertexInSubTree = getVertexOfSubTree(forest, beginVertex, excludeVertex);

    for(auto splitVertex : *vertexInSubTree)
        segments->at(splitVertex) = nextSegmentNumber;

    delete vertexInSubTree;
}

std::list<int>* Segmentation::getVertexOfSubTree(TreeGraph *forest, int beginVertex, int excludeVertex){
    auto vertexInSubTree = new std::list<int>();
    std::vector<bool> seen = std::vector<bool>(forest->getVertex(),false);
    seen.at(excludeVertex) = true;

    auto vertexToVisit = new std::stack<int>();
    vertexToVisit->push(beginVertex);

    int vertex;
    while( !vertexToVisit->empty() ){
        vertex = vertexToVisit->top();
        vertexToVisit->pop();

        vertexInSubTree->emplace_back(vertex);

        for(auto adyacent : *forest->getAdyacents(vertex)) {
            if ( !seen.at(adyacent.first) ) {
                vertexToVisit->push(adyacent.first);
            }
        }
        seen.at(vertex) = true;
    }

    delete vertexToVisit;

    return vertexInSubTree;
}

double Segmentation::mean(std::vector<Edge> *edges) {
    if(edges->empty()) return 1;
    int sum = 0;
    for(auto edge : *edges)
        sum += edge.getWeight();
    return sum / edges->size();
}

bool Segmentation::isInconsistent(double subTreeMean, Distancia W, double sigmaT, double fT) {
    return (W > subTreeMean + sigmaT) && (W / subTreeMean > fT);
}

double Segmentation::desviation(std::vector<Edge> *tree, double mean) {
    double sigma_cuadrado = 0;
    for (auto edge : *tree){
        sigma_cuadrado += pow(edge.getWeight() - mean,2);
    }
    sigma_cuadrado = sigma_cuadrado / tree->size();
    return sqrt(sigma_cuadrado);
}

