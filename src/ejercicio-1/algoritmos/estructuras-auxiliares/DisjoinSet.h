//
// Created by Christian nahuel Rivera on 11/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_DISJOINSET_H
#define TP2_MODELADO_CON_GRAFOS_DISJOINSET_H


#include "../../entities/KruskalKindOfGraph.h"

class DisjoinSet {
public:
    virtual int find(int vertexIndex) = 0;
    virtual void join(int alreadyIn, int newNode) = 0;
    virtual void create(Graph *graph) = 0;
    virtual ~DisjoinSet() { };
};


#endif //TP2_MODELADO_CON_GRAFOS_DISJOINSET_H
