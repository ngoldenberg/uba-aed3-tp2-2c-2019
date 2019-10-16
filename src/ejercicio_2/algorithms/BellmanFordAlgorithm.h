#pragma once

#include <climits>

#include "algorithms/Algorithm.h"
#include "config/constants.h"

class BellmanFordAlgorithm : public Algorithm {
 private:
  tuple<int, int, float> GetEdgeByNumber(FloatMatrix matrix, int n);
  void printArr(int dist[], int n);

 public:
  BellmanFordAlgorithm();
  ~BellmanFordAlgorithm();
  int Solve(int const currencies_quantity, FloatMatrix const &matrix) = 0;
  bool CycleExists(int const currencies_quantity,
              const FloatMatrix &matrix,
              int src_vertex);
};

