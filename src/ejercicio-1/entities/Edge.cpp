//
// Created by Christian nahuel Rivera on 7/10/19.
//

#include <algorithm>
#include "Edge.h"

Edge::Edge(int v1, int v2, Distancia weight) {
    this->fromVertex = std::min(v1, v2);
    this->toVertex = std::max(v1, v2);
    this->weight = weight;
}

int Edge::getFromVertex() const {
    return fromVertex;
}

int Edge::getToVertex() const {
    return toVertex;
}

Distancia Edge::getWeight() const {
    return weight;
}

bool Edge::operator<(const Edge &edge) const {
    return weight > edge.getWeight();
    // TODO: Está hecho a propósito al revez. Esto porque en kruskal no implementé un min heap. Si hace falta hablar conmigo(Chris).
}

bool Edge::operator==(Edge edge) const {
    return this->toVertex == edge.getToVertex() && this->fromVertex == edge.getFromVertex() && this->weight == edge.getWeight();
}
