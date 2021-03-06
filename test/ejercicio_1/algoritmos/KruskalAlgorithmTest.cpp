//
// Created by Christian nahuel Rivera on 6/10/19.
//
#include <gtest/gtest.h>
#include "ejercicio_1/algoritmos/MSTAlgorithm.h"
#include "ejercicio_1/algoritmos/KruskalAlgorithm.h"
#include "ejercicio_1/entities/KruskalKindOfGraph.h"
#include "ejercicio_1/algoritmos/estructuras-auxiliares/ArrayDisjoinSet.h"
#include "ejercicio_1/algoritmos/estructuras-auxiliares/ArrayCompressedDisjoinSet.h"

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

TEST_F(KruskalAlgorithmTest, testing1){
    Graph* graph = new KruskalKindOfGraph(5);
    graph->addEdge(0,1,1);
    graph->addEdge(0,2,7);
    graph->addEdge(1,2,5);
    graph->addEdge(1,4,3);
    graph->addEdge(1,3,4);
    graph->addEdge(2,4,6);
    graph->addEdge(3,4,2);

    TreeGraph treeGraph = *(algorithm->makeMst(graph));

    ASSERT_EQ(4, treeGraph.getEdges().size());
    ASSERT_EQ(11, treeGraph.getWeight());
}

TEST_F(KruskalAlgorithmTest, testing2){
    Graph* graph = new KruskalKindOfGraph(11);
    graph->addEdge(0,1,1);
    graph->addEdge(1,4,2);
    graph->addEdge(4,5,3);
    graph->addEdge(5,10,4);
    graph->addEdge(10,6,5);
    graph->addEdge(10,7,6);
    graph->addEdge(10,8,7);
    graph->addEdge(10,9,8);
    graph->addEdge(4,2,9);
    graph->addEdge(2,3,10);
    graph->addEdge(0,3,20);
    graph->addEdge(4,3,20);
    graph->addEdge(0,2,20);
    graph->addEdge(1,2,20);
    graph->addEdge(5,6,20);
    graph->addEdge(5,9,20);
    graph->addEdge(6,7,20);
    graph->addEdge(7,8,20);
    graph->addEdge(9,8,20);

    TreeGraph treeGraph = *(algorithm->makeMst(graph));

    ASSERT_EQ(10, treeGraph.getEdges().size());
    ASSERT_EQ(55, treeGraph.getWeight());
}

TEST_F(KruskalAlgorithmTest, testing3){
    Graph* graph = new KruskalKindOfGraph(6);
    graph->addEdge(0,1,1);
    graph->addEdge(0,2,1);
    graph->addEdge(0,3,1);
    graph->addEdge(0,4,1);
    graph->addEdge(0,5,1);
    graph->addEdge(1,2,1);
    graph->addEdge(1,3,1);
    graph->addEdge(1,4,1);
    graph->addEdge(1,5,1);
    graph->addEdge(2,3,1);
    graph->addEdge(2,4,1);
    graph->addEdge(2,5,1);
    graph->addEdge(3,4,1);
    graph->addEdge(3,5,1);
    graph->addEdge(4,5,1);

    TreeGraph treeGraph = *(algorithm->makeMst(graph));

    ASSERT_EQ(5, treeGraph.getEdges().size());
    ASSERT_EQ(5, treeGraph.getWeight());
}