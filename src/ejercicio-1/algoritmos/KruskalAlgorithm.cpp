//
// Created by Christian nahuel Rivera on 7/10/19.
//

#include "KruskalAlgorithm.h"
#include <algorithm>

TreeGraph * KruskalAlgorithm::makeMst(Graph *graph) {

    disjoinSet->create(graph);

    std::vector<Edge> edges = graph->getEdges();

    sort(edges.begin(), edges.end());

    TreeGraph *tree = new TreeGraph(graph->getVertex());

    while( /*tree->getEdges().size() < graph->getVertex() &&*/ !edges.empty()){
        Edge edge = edges.back(); edges.pop_back();

        if(disjoinSet->find(edge.getFromVertex()) != disjoinSet->find(edge.getToVertex())){
            tree->addEdge(edge);

            disjoinSet->join(edge.getFromVertex(), edge.getToVertex());
        }
    }
    return tree;
}

KruskalAlgorithm::KruskalAlgorithm(DisjoinSet *disjoinSet) {
    this->disjoinSet = disjoinSet;
}

KruskalAlgorithm::~KruskalAlgorithm() {
    delete disjoinSet;
}
