//
// Created by Christian nahuel Rivera on 11/10/19.
//

#include <gtest/gtest.h>
#include "ejercicio_1/entities/Graph.h"
#include "ejercicio_1/entities/AdyacencyMatrixGraph.h"
#include "ejercicio_1/entities/Utils.h"

struct AdyacencyMatrixGraphTest : testing::Test{
    Graph *graph;
    AdyacencyMatrixGraphTest(){
        graph = new AdyacencyMatrixGraph();
    }

    ~AdyacencyMatrixGraphTest(){
        delete graph;
    }
};

TEST_F(AdyacencyMatrixGraphTest, ConVector2_DevuelvoGrafoCompleto){
    std::vector<Dot> dots;
    dots.emplace_back(std::make_pair(1,1));
    dots.emplace_back(std::make_pair(1,3));

    graph = new AdyacencyMatrixGraph(&dots);

    ASSERT_EQ(2, graph->getVertex());
    ASSERT_TRUE(graph->adyacent(0,1));
    ASSERT_TRUE(graph->adyacent(1,0));
}

TEST_F(AdyacencyMatrixGraphTest, ConVector3_DevuelvoGrafoCompleto){
    std::vector<std::pair<int,int>> dots;
    dots.emplace_back(std::make_pair(0,0));
    dots.emplace_back(std::make_pair(1,0));
    dots.emplace_back(std::make_pair(1,3));

    graph = new AdyacencyMatrixGraph(&dots);

    ASSERT_EQ(1, graph->distance(0,1));
    ASSERT_EQ(3, graph->distance(1,2));
    ASSERT_EQ(3, graph->distance(1,2));

    ASSERT_EQ(3, graph->getVertex());
    ASSERT_TRUE(graph->adyacent(0,1));
    ASSERT_TRUE(graph->adyacent(0,2));
    ASSERT_TRUE(graph->adyacent(1,2));

    ASSERT_TRUE(graph->adyacent(1,0));
    ASSERT_TRUE(graph->adyacent(2,0));
    ASSERT_TRUE(graph->adyacent(2,1));
}

TEST_F(AdyacencyMatrixGraphTest, ConVector5_DevuelvoGrafoCompleto){
    std::vector<std::pair<int,int>> dots;
    dots.emplace_back(std::make_pair(0,1));
    dots.emplace_back(std::make_pair(2,1));
    dots.emplace_back(std::make_pair(1,5));
    dots.emplace_back(std::make_pair(5,5));
    dots.emplace_back(std::make_pair(5,1));

    graph = new AdyacencyMatrixGraph(&dots);

    ASSERT_EQ(5, graph->getVertex());
    ASSERT_TRUE(graph->adyacent(0,1));
    ASSERT_TRUE(graph->adyacent(0,2));
    ASSERT_TRUE(graph->adyacent(0,3));
    ASSERT_TRUE(graph->adyacent(0,4));

    ASSERT_TRUE(graph->adyacent(1,0));
    ASSERT_TRUE(graph->adyacent(1,2));
    ASSERT_TRUE(graph->adyacent(1,3));
    ASSERT_TRUE(graph->adyacent(1,4));

    ASSERT_TRUE(graph->adyacent(2,0));
    ASSERT_TRUE(graph->adyacent(2,1));
    ASSERT_TRUE(graph->adyacent(2,3));
    ASSERT_TRUE(graph->adyacent(2,4));

    ASSERT_TRUE(graph->adyacent(3,0));
    ASSERT_TRUE(graph->adyacent(3,1));
    ASSERT_TRUE(graph->adyacent(3,2));
    ASSERT_TRUE(graph->adyacent(3,4));

    ASSERT_TRUE(graph->adyacent(4,0));
    ASSERT_TRUE(graph->adyacent(4,1));
    ASSERT_TRUE(graph->adyacent(4,2));
    ASSERT_TRUE(graph->adyacent(4,3));
}