//
// Created by Christian nahuel Rivera on 6/10/19.
//

#include "Segmentation.h"
#include "../entities/Graph.h"
#include "../entities/AdyacencyMatrixGraph.h"
#include "../entities/TreeGraph.h"
#include "../entities/KruskalKindOfGraph.h"
#include "BellmanFordAlgorithm.h"
#include "PrimAlgorithm.h"

std::vector<int> Segmentation::execute(std::vector<std::pair<int, int>> *dots) {
    Graph *graph = makeGraph(dots);

    TreeGraph mst = *mstAlgorithm->makeMst(graph);

    //Continuar como dice el paper.

    return std::vector<int>(dots->size(),0);
}

Segmentation::Segmentation(std::string mstAlgorithm) {
    assert(mstAlgorithm == "prim" || mstAlgorithm == "bellman");

    this->mstStrategy = mstAlgorithm;

    if (mstAlgorithm == "prim") {
        this->mstAlgorithm = new PrimAlgorithm();
    } else {
        this->mstAlgorithm = new BellmanFordAlgorithm();
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
