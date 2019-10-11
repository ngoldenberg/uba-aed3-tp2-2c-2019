//
// Created by Christian nahuel Rivera on 7/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_BELLMANFORDALGORITHM_H
#define TP2_MODELADO_CON_GRAFOS_BELLMANFORDALGORITHM_H


#include "MSTAlgorithm.h"

class BellmanFordAlgorithm : public MSTAlgorithm{
public:
    TreeGraph * makeMst(Graph *graph);

};


#endif //TP2_MODELADO_CON_GRAFOS_BELLMANFORDALGORITHM_H
