//
// Created by Christian nahuel Rivera on 6/10/19.
//
#include <gtest/gtest.h>
#include "../../../src/ejercicio-1/algoritmos/MSTAlgorithm.h"
#include "../../../src/ejercicio-1/algoritmos/BellmanFordAlgorithm.h"
#include "../../../src/ejercicio-1/entities/KruskalKindOfGraph.h"

struct KruskalAlgorithmTest : testing::Test{
    MSTAlgorithm *algorithm;

    KruskalAlgorithmTest(){
        algorithm = new BellmanFordAlgorithm();
    }

    ~KruskalAlgorithmTest(){
        delete algorithm;
    }
};

TEST_F(KruskalAlgorithmTest, ConGrafoVacio_DevuelvoArbolVacio){
    Graph* graph = new KruskalKindOfGraph(0);

    TreeGraph treeGraph = *(algorithm->makeMst(graph));

    ASSERT_EQ(0, treeGraph.getEdges().size());
    //ASSERT_EQ(0, treeGraph.getVertex());
}

TEST_F(KruskalAlgorithmTest, ConGrafoSimple_DevuelvoArbol){
    Graph* graph = new KruskalKindOfGraph(3);
    graph->addEdge(1,0,5);
    graph->addEdge(2,0,7);

    TreeGraph treeGraph = *(algorithm->makeMst(graph));

    ASSERT_EQ(2, treeGraph.getEdges().size());
    //ASSERT_EQ(12, treeGraph.getWeigth());

}