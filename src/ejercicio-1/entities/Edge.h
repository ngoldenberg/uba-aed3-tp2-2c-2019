//
// Created by Christian nahuel Rivera on 7/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_EDGE_H
#define TP2_MODELADO_CON_GRAFOS_EDGE_H


#include "Utils.h"

class Edge {
public:
    Edge(int v1, int v2, Distancia weight);

    int getFromVertex() const;

    int getToVertex() const;

    Distancia getWeight() const;

    bool operator<(const Edge& edge)const;

    bool operator==(Edge edge)const;

private:
    int fromVertex;
    int toVertex;
    Distancia weight;

};


#endif //TP2_MODELADO_CON_GRAFOS_EDGE_H
