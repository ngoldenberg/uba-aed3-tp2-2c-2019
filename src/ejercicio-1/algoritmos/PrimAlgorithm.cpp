//
// Created by Christian nahuel Rivera on 7/10/19.
//

#include "PrimAlgorithm.h"

TreeGraph * PrimAlgorithm::makeMst(Graph *graph) {
    return new TreeGraph(graph->getVertex());
}

PrimAlgorithm::~PrimAlgorithm() {

}
