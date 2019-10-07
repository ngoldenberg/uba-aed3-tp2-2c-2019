//
// Created by Christian nahuel Rivera on 6/10/19.
//

#ifndef TP2_MODELADO_CON_GRAFOS_SEGMENTATION_H
#define TP2_MODELADO_CON_GRAFOS_SEGMENTATION_H


#include <vector>
#include <string>
#include "../entities/Graph.h"
#include "../entities/TreeGraph.h"

class Segmentation {
public:
    Segmentation(std::string mstAlgorithm);
    std::vector<int> execute(std::vector<std::pair<int,int>> dots);

private:
    std::string mstAlgorithm;

    Graph makeGraph(std::vector<std::pair<int, int>> dots);

    TreeGraph makeMst(Graph graph);

    TreeGraph primMSTAlgorithm(Graph graph);

    TreeGraph bellmanFordMSTAlgorithm(Graph graph);
};


#endif //TP2_MODELADO_CON_GRAFOS_SEGMENTATION_H
