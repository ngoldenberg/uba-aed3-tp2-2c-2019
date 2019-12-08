//
// Created by Christian nahuel Rivera on 11/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_ARRAYCOMPRESSEDDISJOINSET_H
#define TP2_MODELADO_CON_GRAFOS_ARRAYCOMPRESSEDDISJOINSET_H


#include "DisjoinSet.h"

class ArrayCompressedDisjoinSet : public DisjoinSet {
public:
    /*
     * complejidad O(ahpha(n)) que es una función casi constante
     */
    int find(int vertex);
    /*
     * complejidad O(ahpha(n)) que es una función casi constante
    */
    void join(int alreadyIn, int newNode);
    /*
     * O(n)
     */
    void create(Graph *graph);

private:
    std::vector<int> components;
    std::vector<int> heights;
};


#endif //TP2_MODELADO_CON_GRAFOS_ARRAYCOMPRESSEDDISJOINSET_H
