//
// Created by Christian nahuel Rivera on 7/10/19.
//

#include <cmath>
#include "KruskalKindOfGraph.h"

KruskalKindOfGraph::KruskalKindOfGraph(std::vector<Dot> *dots) {
    vertexSize = dots->size();

    for(int i = 0; i < dots->size(); i++){
        for(int j = i+1; j < dots->size(); j++){
            int xi = dots->at(i).first;
            int xj = dots->at(j).first;
            int yi = dots->at(i).second;
            int yj = dots->at(j).second;
            if(!( areEquivalent(xi, xj, yi, yj))){
                edges.emplace_back( Edge(i,j,getDistanceBetweenPoints(xi, xj, yi, yj) ));
            }
        }
    }
}

double KruskalKindOfGraph::getDistanceBetweenPoints(int xi, int xj, int yi, int yj) const {
    return sqrt(pow(xi - xj, 2) + pow(yi - yj, 2));
    // TODO: PUEDE QUE SEA INNECESARIO TENER EL REDONDEO.
}

bool KruskalKindOfGraph::areEquivalent(int xi, int xj, int yi, int yj) const {
    return xi == xj && yi == yj;
}

std::vector<Edge> KruskalKindOfGraph::getEdges() {
    return edges;
}

KruskalKindOfGraph::KruskalKindOfGraph(int size) {
    vertexSize = size;
}

void KruskalKindOfGraph::addEdge(int from, int to, Distancia weigth) {
    edges.emplace_back(Edge(from,to,weigth));
}

bool KruskalKindOfGraph::adyacent(int v1, int v2) {
    for(Edge edge : edges){
        if((edge.getToVertex() == v1 && edge.getFromVertex() == v2) ||
        (edge.getFromVertex() == v1 && edge.getToVertex() == v2) ){
            return true;
        }
    }
    return false;
}

KruskalKindOfGraph::KruskalKindOfGraph() {

}

int KruskalKindOfGraph::getVertex() {
    return vertexSize;
}

long KruskalKindOfGraph::distance(int v1, int v2) {
    return NotDefined;
}
