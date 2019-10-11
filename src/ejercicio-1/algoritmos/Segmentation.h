//
// Created by Christian nahuel Rivera on 6/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_SEGMENTATION_H
#define TP2_MODELADO_CON_GRAFOS_SEGMENTATION_H


#include <vector>
#include <string>
#include "../entities/Graph.h"
#include "../entities/TreeGraph.h"
#include "MSTAlgorithm.h"

class Segmentation {
public:
    Segmentation(std::string mstAlgorithm);
    ~Segmentation();
    std::vector<int> execute(std::vector<std::pair<int,int>> *dots);

private:
    std::string mstStrategy;
    MSTAlgorithm* mstAlgorithm;

    Graph *makeGraph(std::vector<std::pair<int, int>> *dots);

};


#endif //TP2_MODELADO_CON_GRAFOS_SEGMENTATION_H
