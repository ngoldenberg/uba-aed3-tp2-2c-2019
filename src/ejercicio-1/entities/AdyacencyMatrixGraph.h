//
// Created by Christian nahuel Rivera on 6/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_ADYACENCYMATRIXGRAPH_H
#define TP2_MODELADO_CON_GRAFOS_ADYACENCYMATRIXGRAPH_H


#include "Graph.h"

class AdyacencyMatrixGraph : public Graph {
public:
    AdyacencyMatrixGraph();

    std::vector<Edge> getEdges() override;

    explicit AdyacencyMatrixGraph(std::vector<std::pair<int, int>> *pVector);

    void addEdge(int from, int to, int weigth) override;

    bool adyacent(int v1, int v2);

    int getVertex();

    // Primero preguntar si son adyacentes
    long distance(int v1, int v2) override;


private:
    std::vector<std::vector<long>> matrix;
    bool areEquivalent(int xi, int xj, int yi, int yj) const;

    long getDistanceBetweenPoints(int xi, int xj, int yi, int yj) const;
};


#endif //TP2_MODELADO_CON_GRAFOS_ADYACENCYMATRIXGRAPH_H
