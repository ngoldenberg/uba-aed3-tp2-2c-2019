//
// Created by Christian nahuel Rivera on 7/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_TREEGRAPH_H
#define TP2_MODELADO_CON_GRAFOS_TREEGRAPH_H


#include <vector>
#include <list>
#include "Edge.h"
#include "Graph.h"
#define Destino int


class TreeGraph {
public:
    explicit TreeGraph(int vertexSize);

    ~TreeGraph();

    std::vector<Edge> getEdges();
    int getVertex();
    Distancia getWeigth();

    void addEdge(Edge edge);
    void deleteEdge(Edge edge);

    std::list<std::pair<int, Distancia>> * getAdyacents(int vertex);

private:
    std::vector<std::list<std::pair<Destino,Distancia>>> adyacencias;

    std::vector<Edge> edges;
};


#endif //TP2_MODELADO_CON_GRAFOS_TREEGRAPH_H
