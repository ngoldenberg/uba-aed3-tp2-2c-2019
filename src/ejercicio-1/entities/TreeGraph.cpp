//
// Created by Christian nahuel Rivera on 7/10/19.
//

#include "TreeGraph.h"

std::vector<Edge> TreeGraph::getEdges() {
    return edges;
}

int TreeGraph::getVertex() {
    return adyacencias.size();
}

Distancia TreeGraph::getWeigth() {
    Distancia weigth = 0;

    for(auto edge : edges){
        weigth+= edge.getWeith();
    }

    return weigth;
}

TreeGraph::TreeGraph(int vertexSize) {
    /*
    for(int index = 0; index < vertexSize; index++){
        adyacencias.emplace_back(std::list<std::pair<Distancia,Destino>>());
    }
     */
    adyacencias.resize(vertexSize);
    assert(adyacencias.size() == vertexSize);
}

void TreeGraph::addEdge(Edge edge) {
    adyacencias.at(edge.getFromVertex()).emplace_back(std::make_pair(edge.getToVertex(), edge.getWeith()));
    adyacencias.at(edge.getToVertex()).emplace_back(std::make_pair(edge.getFromVertex(), edge.getWeith()));

    edges.emplace_back(edge);
}

void TreeGraph::deleteEdge(Edge edge) {

}

std::list<std::pair<int, long>> * TreeGraph::getAdyacents(int vertex) {
    return &adyacencias.at(vertex);
}


