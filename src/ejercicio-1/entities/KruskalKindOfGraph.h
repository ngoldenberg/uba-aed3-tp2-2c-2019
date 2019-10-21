//
// Created by Christian nahuel Rivera on 7/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_BELLMANKINDOFGRAPH_H
#define TP2_MODELADO_CON_GRAFOS_BELLMANKINDOFGRAPH_H

#include "Utils.h"
#include "Graph.h"

class KruskalKindOfGraph : public Graph {
public:
    KruskalKindOfGraph();

    KruskalKindOfGraph(int size);

    std::vector<Edge> getEdges() ;

    KruskalKindOfGraph(std::vector<Dot> *pVector);

    void addEdge(int from, int to, Distancia weigth) ;

    bool adyacent(int v1, int v2) ;

    int getVertex() override;

    // Primero preguntar si son adyacentes
    long distance(int v1, int v2) override;

private:
    int vertexSize;
    std::vector<Edge> edges;

    bool areEquivalent(int xi, int xj, int yi, int yj) const;

    double getDistanceBetweenPoints(int xi, int xj, int yi, int yj) const;
};


#endif //TP2_MODELADO_CON_GRAFOS_BELLMANKINDOFGRAPH_H
