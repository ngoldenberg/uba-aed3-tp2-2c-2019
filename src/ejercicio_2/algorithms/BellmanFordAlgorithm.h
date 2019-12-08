#pragma once

#include <climits>
#include <iostream>

#include "Algorithm.h"
#include "config/constants.h"
#include <cmath>
#include <vector>

class BellmanFordAlgorithm : public Algorithm {
 private:
  vector<int> GetCycle(struct Graph *graph, int src, const FloatMatrix &matrix);
  static int GetEdgeNumberByAxis(FloatMatrix const &matrix, int r, int c);
  bool In(int n, vector<int> list);

 public:
  BellmanFordAlgorithm() {};
  ~BellmanFordAlgorithm() {};
  std::vector<int> Solve(int const currencies_quantity, FloatMatrix const &matrix) override;
};

