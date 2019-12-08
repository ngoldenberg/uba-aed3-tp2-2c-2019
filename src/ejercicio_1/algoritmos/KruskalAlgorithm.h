//
// Created by Christian nahuel Rivera on 7/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_BELLMANFORDALGORITHM_H
#define TP2_MODELADO_CON_GRAFOS_BELLMANFORDALGORITHM_H


#include "MSTAlgorithm.h"
#include "estructuras-auxiliares/DisjoinSet.h"

class KruskalAlgorithm : public MSTAlgorithm{
public:
    explicit KruskalAlgorithm(DisjoinSet *disjoinSet);
    ~KruskalAlgorithm();
    TreeGraph * makeMst(Graph *graph);

private:
    DisjoinSet *disjoinSet;
};


#endif //TP2_MODELADO_CON_GRAFOS_BELLMANFORDALGORITHM_H
