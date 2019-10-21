//
// Created by Christian nahuel Rivera on 7/10/19.
//

#include "TreeGraph.h"

std::vector<Edge> TreeGraph::getEdges() {
    return edges;
}

int TreeGraph::getVertex() {
    return vertex;
}

long TreeGraph::getWeight() {
    long weigth = 0;
    for(auto edge : edges){
        weigth += edge.getWeight();
    }
    return weigth;
}

TreeGraph::TreeGraph(int vertexSize) {
    vertex = vertexSize;
}

void TreeGraph::addEdge(Edge edge) {
    edges.emplace_back(edge);
}

