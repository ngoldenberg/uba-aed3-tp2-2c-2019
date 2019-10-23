//
// Created by Christian nahuel Rivera on 6/10/19.
//
#include <gtest/gtest.h>
#include "../../../src/ejercicio-1/algoritmos/MSTAlgorithm.h"
#include "../../../src/ejercicio-1/algoritmos/KruskalAlgorithm.h"
#include "../../../src/ejercicio-1/entities/KruskalKindOfGraph.h"
#include "../../../src/ejercicio-1/algoritmos/estructuras-auxiliares/ArrayDisjoinSet.h"
#include "../../../src/ejercicio-1/algoritmos/estructuras-auxiliares/ArrayCompressedDisjoinSet.h"

struct KruskalAlgorithmTest : testing::Test{
    MSTAlgorithm *algorithm;

    KruskalAlgorithmTest(){
        algorithm = new KruskalAlgorithm(new ArrayDisjoinSet());
        //algorithm = new KruskalAlgorithm(new ArrayCompressedDisjoinSet());
    }

    ~KruskalAlgorithmTest(){
        delete algorithm;
    }
};

TEST_F(KruskalAlgorithmTest, ConGrafoVacio_DevuelvoArbolVacio){
    Graph* graph = new KruskalKindOfGraph(0);

    TreeGraph treeGraph = *(algorithm->makeMst(graph));

    ASSERT_EQ(0, treeGraph.getEdges().size());
    ASSERT_EQ(0, treeGraph.getVertex());
}

TEST_F(KruskalAlgorithmTest, ConGrafoSimple_DevuelvoArbol){
    Graph* graph = new KruskalKindOfGraph(3);
    graph->addEdge(1,0,5);
    graph->addEdge(2,0,7);

    TreeGraph treeGraph = *(algorithm->makeMst(graph));

    ASSERT_EQ(2, treeGraph.getEdges().size());
    ASSERT_EQ(12, treeGraph.getWeight());
}

TEST_F(KruskalAlgorithmTest, ConGrafoWikipedia_DevuelvoArbol){
    Graph* graph = new KruskalKindOfGraph(7);
    graph->addEdge(0,1,7);
    graph->addEdge(3,0,5);
    graph->addEdge(1,2,8);
    graph->addEdge(1,3,9);
    graph->addEdge(1,4,7);
    graph->addEdge(2,4,5);
    graph->addEdge(3,4,15);
    graph->addEdge(3,5,6);
    graph->addEdge(4,5,8);
    graph->addEdge(4,6,9);
    graph->addEdge(5,6,11);

    TreeGraph treeGraph = *(algorithm->makeMst(graph));

    ASSERT_EQ(6, treeGraph.getEdges().size());
    ASSERT_EQ(39, treeGraph.getWeight());
}