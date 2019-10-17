//
// Created by Christian nahuel Rivera on 15/10/19.
//

#include <gtest/gtest.h>
#include "../../../src/ejercicio-1/algoritmos/Segmentation.h"

bool containsEdge(std::vector<Edge> edges, Edge edge);

struct SegmentationTest : testing::Test{
    Segmentation *segmentation;

    SegmentationTest(){
        segmentation = new Segmentation("kruskal-compressed");
    }

    ~SegmentationTest(){
        delete segmentation;
    }
};

TEST_F(SegmentationTest, getSubTree_test1){
    TreeGraph tree = TreeGraph(5);
    tree.addEdge(Edge(2,3,1));
    tree.addEdge(Edge(2,1,2));
    tree.addEdge(Edge(0,1,3));
    tree.addEdge(Edge(4,2,5));

    std::vector<Edge> edges = *segmentation->getSubTree(2,&tree,1,3);

    ASSERT_EQ(2, edges.size());
    ASSERT_TRUE(containsEdge(edges,Edge(2,4,5)));
    ASSERT_TRUE(containsEdge(edges,Edge(2,1,2)));
    ASSERT_FALSE(containsEdge(edges,Edge(1,0,3)));
}

TEST_F(SegmentationTest, getSubTree_test2){
    TreeGraph tree = TreeGraph(7);
    tree.addEdge(Edge(2,3,1));
    tree.addEdge(Edge(3,4,2));
    tree.addEdge(Edge(2,1,3));
    tree.addEdge(Edge(6,1,5));
    tree.addEdge(Edge(0,1,5));
    tree.addEdge(Edge(0,5,6));

    std::vector<Edge> edges = *segmentation->getSubTree(2,&tree,2,3);

    ASSERT_EQ(3, edges.size());
    ASSERT_TRUE(containsEdge(edges,Edge(2,1,3)));
    ASSERT_TRUE(containsEdge(edges,Edge(6,1,5)));
    ASSERT_TRUE(containsEdge(edges,Edge(1,0,5)));
    ASSERT_FALSE(containsEdge(edges,Edge(5,0,6)));
}

TEST_F(SegmentationTest, getSubTree_test3){
    TreeGraph tree = TreeGraph(12);
    tree.addEdge(Edge(1,0,1));
    tree.addEdge(Edge(1,2,1));
    tree.addEdge(Edge(1,3,1));
    tree.addEdge(Edge(1,4,1));
    tree.addEdge(Edge(2,5,1));
    tree.addEdge(Edge(2,6,1));
    tree.addEdge(Edge(4,7,1));
    tree.addEdge(Edge(6,8,1));
    tree.addEdge(Edge(6,9,1));
    tree.addEdge(Edge(9,10,1));
    tree.addEdge(Edge(10,11,1));

    std::vector<Edge> edges = *segmentation->getSubTree(1,&tree,3,0);

    ASSERT_EQ(8, edges.size());
    ASSERT_TRUE(containsEdge(edges,Edge(2,1,1)));
    ASSERT_TRUE(containsEdge(edges,Edge(3,1,1)));
    ASSERT_TRUE(containsEdge(edges,Edge(4,1,1)));
    ASSERT_TRUE(containsEdge(edges,Edge(4,7,1)));
    ASSERT_TRUE(containsEdge(edges,Edge(2,6,1)));
    ASSERT_TRUE(containsEdge(edges,Edge(2,5,1)));
    ASSERT_TRUE(containsEdge(edges,Edge(8,6,1)));
    ASSERT_TRUE(containsEdge(edges,Edge(9,6,1)));
    ASSERT_FALSE(containsEdge(edges,Edge(1,0,1)));
    ASSERT_FALSE(containsEdge(edges,Edge(9,10,1)));
    ASSERT_FALSE(containsEdge(edges,Edge(11,10,1)));
}

bool containsEdge(std::vector<Edge> edges, Edge edge){
    bool contain = false;
    for(auto edgeI : edges){
        if(edgeI == edge ){
            contain = true;
        }
    }
    return contain;
}