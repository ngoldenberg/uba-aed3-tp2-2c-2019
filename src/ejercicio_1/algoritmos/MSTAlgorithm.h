//
// Created by Christian nahuel Rivera on 7/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_MSTSTRATEGY_H
#define TP2_MODELADO_CON_GRAFOS_MSTSTRATEGY_H


#include "../entities/TreeGraph.h"
#include "../entities/Graph.h"

class MSTAlgorithm {
public:
    virtual TreeGraph * makeMst(Graph *graph) = 0;

};


#endif //TP2_MODELADO_CON_GRAFOS_MSTSTRATEGY_H
