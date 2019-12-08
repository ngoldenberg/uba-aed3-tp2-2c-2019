//
// Created by Christian nahuel Rivera on 7/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_PRIMALGORITHM_H
#define TP2_MODELADO_CON_GRAFOS_PRIMALGORITHM_H


#include "MSTAlgorithm.h"

class PrimAlgorithm : public MSTAlgorithm{
public:
    TreeGraph * makeMst(Graph *graph) override;

};


#endif //TP2_MODELADO_CON_GRAFOS_PRIMALGORITHM_H
