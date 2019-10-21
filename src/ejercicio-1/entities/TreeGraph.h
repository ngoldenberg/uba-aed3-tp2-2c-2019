//
// Created by Christian nahuel Rivera on 7/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_TREEGRAPH_H
#define TP2_MODELADO_CON_GRAFOS_TREEGRAPH_H


#include <vector>
#include "Edge.h"
#include "Graph.h"

class TreeGraph {
public:
    explicit TreeGraph(int vertexSize);

    std::vector<Edge> getEdges();
    int getVertex();
    long getWeight();

    void addEdge(Edge edge);

private:
    int vertex;
    std::vector<Edge> edges;
};


#endif //TP2_MODELADO_CON_GRAFOS_TREEGRAPH_H
