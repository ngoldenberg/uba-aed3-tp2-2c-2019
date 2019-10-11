//
// Created by Christian nahuel Rivera on 7/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_EDGE_H
#define TP2_MODELADO_CON_GRAFOS_EDGE_H


class Edge {
public:
    Edge(int v1, int v2, long weith);

    int getFromVertex() const;

    int getToVertex() const;

    long getWeith() const;

private:
    int fromVertex;
    int toVertex;
    long weith;

};


#endif //TP2_MODELADO_CON_GRAFOS_EDGE_H
