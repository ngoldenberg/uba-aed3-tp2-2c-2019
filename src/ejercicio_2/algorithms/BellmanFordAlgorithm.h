#pragma once

#include <climits>
#include <iostream>

#include "Algorithm.h"
#include "ejercicio_2/config/constants.h"

class BellmanFordAlgorithm : public Algorithm {
 private:
  tuple<int, int, float> GetEdgeByNumber(FloatMatrix matrix, int n);
  AdjList GetAdjacencyList(const FloatMatrix matrix);
  vector<int> GetCycle(int const currencies_quantity,
                       const FloatMatrix &matrix,
                       int src_vertex);
  void GetNegativeCycle(vector<pair<float, int>> const &shortest_distances,
                        int vertex,
                        int start_vertex, vector<int> &cycle);
  int GetEdgeNumberByAxis(FloatMatrix const &matrix, int r, int c);

 public:
  BellmanFordAlgorithm() {};
  ~BellmanFordAlgorithm() {};
  vector<int> Solve(int const currencies_quantity, FloatMatrix const &matrix) override;
};

