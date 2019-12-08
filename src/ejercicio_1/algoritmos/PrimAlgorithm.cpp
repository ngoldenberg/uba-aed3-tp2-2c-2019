//
// Created by Christian nahuel Rivera on 7/10/19.
//

#include "PrimAlgorithm.h"
#include <algorithm>
#include <climits>

bool estanTodosVisitados(std::vector<bool>* visitado) {
    for (auto v : *visitado) {
        if (!v) return false;
    }
    return true;
}

int nodoDeMenorDistanciaNovisitadoAun(std::vector<int> distancia, std::vector<bool> visitado){
    int min;
    for (int j = 0; j < visitado.size(); ++j) {
        if (!visitado[j]) {
            min = j;
            break;
        }
    }

    for (int i = 0; i < distancia.size(); ++i) {
        if (!visitado[i]) {
            if (distancia[i] < distancia[min]) min = i;
        }
    }
    return min;
}


TreeGraph * PrimAlgorithm::makeMst(Graph *graph){
    if ( 0 == graph->getVertex() ) return new TreeGraph(graph->getVertex());
    std::vector<bool> visitado(graph->getVertex(), false);
    std::vector<int> distancia(graph->getVertex(), INT_MAX);
    std::vector<int> padre(graph->getVertex(), -1);
    for (int i=1; i<graph->getVertex(); i++) {
        if (graph->adyacent(0,i)) { // tomo arbitrariamente el nodo 0 para empezar
            distancia[i] = graph->distance(0,i);
            padre[i] = 0;
        }
    }
    distancia[0] = 0;
    visitado[0] = true;
    while(!estanTodosVisitados(&visitado)) {
        int v = nodoDeMenorDistanciaNovisitadoAun(distancia, visitado);
        visitado[v] = true;
        for (int w=0; w<graph->getVertex(); w++){
            if (graph->adyacent(v,w) and !visitado[w]) {
                if (distancia[w] > graph->distance(v,w)){
                    distancia[w] = graph->distance(v,w);
                    padre[w] = v;
                }
            }
        }
    }
    TreeGraph* tree = new TreeGraph(graph->getVertex());
    for (int i=1; i< graph->getVertex(); i++) {
        tree->addEdge(Edge(i,padre[i],graph->distance(i, padre[i])));
    }


    return tree;
}
