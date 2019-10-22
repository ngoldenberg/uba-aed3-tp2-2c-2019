#pragma once

#include "config/constants.h"

class Algorithm {
 public:
  Algorithm() {}
  virtual ~Algorithm() {}
  virtual vector<int> Solve(int const currencies_quantity, FloatMatrix const &matrix) = 0;
};

