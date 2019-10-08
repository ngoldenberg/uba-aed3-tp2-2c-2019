#pragma once

#include "algorithms/Algorithm.h"
#include "config/constants.h"

class BellmanFordAlgorithm : public Algorithm {
 public:
  BellmanFordAlgorithm();
  ~BellmanFordAlgorithm();
  int Solve(int const currencies_quantity, FloatMatrix const &matrix) = 0;

};

