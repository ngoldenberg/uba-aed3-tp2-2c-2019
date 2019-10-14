//
// Created by Christian nahuel Rivera on 7/10/19.
//

#include <gtest/gtest.h>
#include "../../../src/ejercicio-1/entities/KruskalKindOfGraph.h"

struct KruskalKindOfGraphTest : testing::Test{
    Graph *graph;
    KruskalKindOfGraphTest(){
        graph = new KruskalKindOfGraph();
    }

    ~KruskalKindOfGraphTest(){
        delete graph;
    }
};

TEST_F(KruskalKindOfGraphTest, ConVector2_DevuelvoGrafoCompleto){
    std::vector<Dot> dots;
    dots.emplace_back(std::make_pair(1,1));
    dots.emplace_back(std::make_pair(1,3));

    graph = new KruskalKindOfGraph(&dots);


    ASSERT_EQ(1, graph->getEdges().size());
    ASSERT_EQ(2, graph->getEdges().at(0).getWeith());

    ASSERT_EQ(2, graph->getVertex());
    ASSERT_TRUE(graph->adyacent(0,1));
    ASSERT_TRUE(graph->adyacent(1,0));
}

TEST_F(KruskalKindOfGraphTest, ConVector3_DevuelvoGrafoCompleto){
    std::vector<std::pair<int,int>> dots;
    dots.emplace_back(std::make_pair(0,0));
    dots.emplace_back(std::make_pair(1,0));
    dots.emplace_back(std::make_pair(1,3));

    graph = new KruskalKindOfGraph(&dots);

    ASSERT_EQ(3, graph->getEdges().size());
    ASSERT_EQ(1, graph->getEdges().at(0).getWeith());
    ASSERT_EQ(3, graph->getEdges().at(1).getWeith());
    ASSERT_EQ(3, graph->getEdges().at(2).getWeith());

    ASSERT_EQ(3, graph->getVertex());
    ASSERT_TRUE(graph->adyacent(0,1));
    ASSERT_TRUE(graph->adyacent(0,2));
    ASSERT_TRUE(graph->adyacent(1,2));

    ASSERT_TRUE(graph->adyacent(1,0));
    ASSERT_TRUE(graph->adyacent(2,0));
    ASSERT_TRUE(graph->adyacent(2,1));
}

TEST_F(KruskalKindOfGraphTest, ConVector5_DevuelvoGrafoCompleto){
    std::vector<std::pair<int,int>> dots;
    dots.emplace_back(std::make_pair(0,1));
    dots.emplace_back(std::make_pair(2,1));
    dots.emplace_back(std::make_pair(1,5));
    dots.emplace_back(std::make_pair(5,5));
    dots.emplace_back(std::make_pair(5,1));

    graph = new KruskalKindOfGraph(&dots);

    ASSERT_EQ(5, graph->getVertex());
    ASSERT_EQ(10, graph->getEdges().size());
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

TEST_F(KruskalKindOfGraphTest, ConTamañoYEjes_DevuelvoGrafo){
    graph = new KruskalKindOfGraph(3);

    graph->addEdge(0,1,5);
    graph->addEdge(1,2,10);
    graph->addEdge(0,2,10);

    ASSERT_EQ(3, graph->getEdges().size());
    ASSERT_TRUE(graph->adyacent(0,1));
    ASSERT_TRUE(graph->adyacent(1,2));
    ASSERT_TRUE(graph->adyacent(0,2));
    ASSERT_TRUE(graph->adyacent(2,1));
    ASSERT_TRUE(graph->adyacent(2,0));
}

TEST_F(KruskalKindOfGraphTest, ordenarEjes1){
    graph = new KruskalKindOfGraph(3);
    graph->addEdge(1,2,10);
    graph->addEdge(0,1,5);
    graph->addEdge(0,2,7);
    std::vector<Edge> edges = graph->getEdges();

    sort(edges.begin(), edges.end());

    ASSERT_EQ(10, edges.at(0).getWeith());
    ASSERT_EQ(7, edges.at(1).getWeith());
    ASSERT_EQ(5, edges.at(2).getWeith());
}

TEST_F(KruskalKindOfGraphTest, ordenarEjes2){
    graph = new KruskalKindOfGraph(5);
    graph->addEdge(1,2,1);
    graph->addEdge(3,2,10);
    graph->addEdge(0,1,5);
    graph->addEdge(4,1,3);
    graph->addEdge(0,2,7);
    std::vector<Edge> edges = graph->getEdges();

    sort(edges.begin(), edges.end());

    ASSERT_EQ(10, edges.at(0).getWeith());
    ASSERT_EQ(7, edges.at(1).getWeith());
    ASSERT_EQ(5, edges.at(2).getWeith());
    ASSERT_EQ(3, edges.at(3).getWeith());
    ASSERT_EQ(1, edges.at(4).getWeith());
}
