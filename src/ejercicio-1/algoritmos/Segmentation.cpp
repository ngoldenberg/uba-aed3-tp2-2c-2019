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

std::vector<int> Segmentation::execute(std::vector<std::pair<int, int>> *dots) {
    Graph *graph = makeGraph(dots);

    TreeGraph mst = *mstAlgorithm->makeMst(graph);

    //Continuar como dice el paper.

    return std::vector<int>(dots->size(),0);
}

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
