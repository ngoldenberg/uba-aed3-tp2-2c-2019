//
// Created by Christian nahuel Rivera on 6/10/19.
//

#include "Segmentation.h"
#include "../entities/Graph.h"
#include "../entities/AdyacencyMatrixGraph.h"
#include "../entities/TreeGraph.h"
#include "../entities/BellmanKindOfGraph.h"

std::vector<int> Segmentation::execute(std::vector<std::pair<int, int>> dots) {
    Graph graph = makeGraph(dots);

    TreeGraph mst = makeMst(graph);

    //Continuar como dice el paper.

    return std::vector<int>(dots.size(),0);
}

Segmentation::Segmentation(std::string mstAlgorithm) {
    assert(mstAlgorithm == "prim" || mstAlgorithm == "bellman");
    this->mstAlgorithm = mstAlgorithm;
}

Graph Segmentation::makeGraph(std::vector<std::pair<int, int>> dots) {
    if(mstAlgorithm == "prim"){
        return AdyacencyMatrixGraph();
    }else{
        return BellmanKindOfGraph();
    }
}

TreeGraph Segmentation::makeMst(Graph graph) {
    if(mstAlgorithm == "prim"){
        return primMSTAlgorithm(graph);
    }else{
        return bellmanFordMSTAlgorithm(graph);
    }
}

TreeGraph Segmentation::primMSTAlgorithm(Graph graph) {
    return TreeGraph();
}

TreeGraph Segmentation::bellmanFordMSTAlgorithm(Graph graph) {
    return TreeGraph();
}
