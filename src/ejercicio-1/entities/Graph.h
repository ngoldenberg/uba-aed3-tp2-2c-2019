//
// Created by Christian nahuel Rivera on 6/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_GRAPH_H
#define TP2_MODELADO_CON_GRAFOS_GRAPH_H


#include <vector>
#include "Edge.h"

class Graph {
public:
    virtual std::vector<Edge> getEdges() =0;

    virtual void addEdge(int from, int to, int weigth) =0;

    virtual bool adyacent(int v1, int v2) =0;

    virtual int getVertex() =0;

    virtual long distance(int v1, int v2) =0;
};


#endif //TP2_MODELADO_CON_GRAFOS_GRAPH_H
