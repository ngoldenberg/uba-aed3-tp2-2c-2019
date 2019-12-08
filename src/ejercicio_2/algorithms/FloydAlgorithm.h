#pragma once

#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

#include "Algorithm.h"
#include "config/constants.h"

class FloydAlgorithm : public Algorithm {
 public:
  FloydAlgorithm() {};
  ~FloydAlgorithm() {};
  vector<int> Solve(int const currencies_quantity, FloatMatrix const &matrix) override;

 private:
  int GetEdgeNumberByAxis(const FloatMatrix &matrix, int r, int c);
};

