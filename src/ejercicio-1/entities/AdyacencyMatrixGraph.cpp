//
// Created by Christian nahuel Rivera on 6/10/19.
//

#include "AdyacencyMatrixGraph.h"
#include "Utils.h"
#include <cmath>
#include "assert.h"

AdyacencyMatrixGraph::AdyacencyMatrixGraph(std::vector<Dot> *dots) {
    for(int iter = 0; iter < dots->size(); iter ++){
        matrix.emplace_back(std::vector<Distancia>(dots->size(), NotDefined));
    }

    for(int i = 0; i < dots->size(); i++){
        for(int j = i+1; j < dots->size(); j++){
            int xi = dots->at(i).first;
            int xj = dots->at(j).first;
            int yi = dots->at(i).second;
            int yj = dots->at(j).second;
            if(!( areEquivalent(xi, xj, yi, yj))){
                matrix[i][j] = getDistanceBetweenPoints(xi, xj, yi, yj);
                matrix[j][i] = getDistanceBetweenPoints(xi, xj, yi, yj);
            }
        }
    }
}

double AdyacencyMatrixGraph::getDistanceBetweenPoints(int xi, int xj, int yi, int yj) const {
    return sqrt(pow(xi - xj, 2) + pow(yi - yj, 2));
}

bool AdyacencyMatrixGraph::areEquivalent(int xi, int xj, int yi, int yj) const {
    return xi == xj && yi == yj;
}

std::vector<Edge> AdyacencyMatrixGraph::getEdges() {
    return std::vector<Edge>();
}

void AdyacencyMatrixGraph::addEdge(int from, int to, Distancia weigth) {}

bool AdyacencyMatrixGraph::adyacent(int v1, int v2) {
    return matrix.at(v1).at(v2) != NotDefined;
}

int AdyacencyMatrixGraph::getVertex() {
    return matrix.size();
}

AdyacencyMatrixGraph::AdyacencyMatrixGraph(int size) {
    for(int iter = 0; iter < size; iter ++){
        matrix.emplace_back(std::vector<Distancia>(size, NotDefined));
    }
}

long AdyacencyMatrixGraph::distance(int v1, int v2) {
    assert(adyacent(v1,v2));
    return matrix.at(v1).at(v2);
}

AdyacencyMatrixGraph::AdyacencyMatrixGraph() {
}
