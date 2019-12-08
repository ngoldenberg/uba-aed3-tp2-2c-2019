#pragma once

#include <climits>
#include <iostream>

#include "Algorithm.h"
#include "config/constants.h"
#include <cmath>
#include <vector>

class BellmanFordAlgorithm : public Algorithm {
 private:
  std::tuple<int, int, float> GetEdgeByNumber(FloatMatrix matrix, int n);
  AdjList GetAdjacencyList(const FloatMatrix matrix);
  vector<int> GetCycle(struct Graph *graph, int src, const FloatMatrix &matrix);
  void GetNegativeCycle(vector<pair<float, int>> const &shortest_distances,
                        int vertex,
                        int start_vertex, vector<int> &cycle);
  int GetEdgeNumberByAxis(FloatMatrix const &matrix, int r, int c);
  bool In(int n, vector<int> list);

 public:
  BellmanFordAlgorithm() {};
  ~BellmanFordAlgorithm() {};
  std::vector<int> Solve(int const currencies_quantity, FloatMatrix const &matrix) override;
};

