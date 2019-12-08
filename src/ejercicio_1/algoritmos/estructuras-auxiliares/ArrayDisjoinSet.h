//
// Created by Christian nahuel Rivera on 11/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_ARRAYDISJOINSET_H
#define TP2_MODELADO_CON_GRAFOS_ARRAYDISJOINSET_H


#include "DisjoinSet.h"

class ArrayDisjoinSet : public DisjoinSet {
public:
    /*
     * complejidad O(1)
     */
    int find(int vertex);
    /*
     * complejidad O(n)
     */
    void join(int alreadyIn, int newNode);
    /*
     * complejidad O(n)
     */
    void create(Graph *graph);


protected:
    std::vector<int> components;
};


#endif //TP2_MODELADO_CON_GRAFOS_ARRAYDISJOINSET_H
