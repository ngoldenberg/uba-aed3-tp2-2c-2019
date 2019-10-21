//
// Created by Christian nahuel Rivera on 7/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_EDGE_H
#define TP2_MODELADO_CON_GRAFOS_EDGE_H


class Edge {
public:
    Edge(int v1, int v2, long weight);

    int getFromVertex() const;

    int getToVertex() const;

    long getWeight() const;

    bool operator<(const Edge& edge)const;

private:
    int fromVertex;
    int toVertex;
    long weight;

};


#endif //TP2_MODELADO_CON_GRAFOS_EDGE_H
