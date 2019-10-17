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

    std::vector<int> execute(std::vector<std::pair<int, int>> *dots, double depth, double sigmaT, double fT);

    /*
     * @params:
     * - fromVertex: es el nodo origen desde el cual armo el sub grafo.
     * - graph: grafo en cuestión. Al comienzo en conexo pero a lo largo del algoritmo puede dejar de serlo.
     * - depth: profundidad con la que se deben buscar los ejes en el grafo.
     * - excludeVertex: extremo del eje original que se debe omitir.
     *
     * @return:
     * Un vector con todos los ejes que cumplen con comenzar por el fromVertex, siendo adyacente a él y alejandose
     * del mismo con una distancia de hasta depth desde este vértice.
     *
     * @ modifica a graph.
     */
    std::vector<Edge> * getSubTree(int fromVertex, TreeGraph *graph, double depth, int excludeVertex);

    /*
     * Inicializo el grafo que voy a utilizar a partir de una lista de puntos (coordenadas en x e y).
     */
    Graph *makeGraph(std::vector<std::pair<int, int>> *dots);


    /*
     * Responde si edge es "inconsistente" según los principios del paper.
     */
    bool isInconsistent(Edge edge, std::vector<Edge> *leftSubTree, std::vector<Edge> *rigthSubTree, double sigmaT,
                        double fT);

    /*
     * modifica a segments.
     * separa a los nodos adyacentes al extremo del toVertex del edge en una nueva componente.
     */
    void splitSegments(std::vector<int> segments, TreeGraph tree, Edge edge, int nextSegmentNumber);

private:
    std::string mstStrategy;
    MSTAlgorithm* mstAlgorithm;

    };


#endif //TP2_MODELADO_CON_GRAFOS_SEGMENTATION_H
