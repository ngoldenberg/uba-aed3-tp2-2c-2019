#include "BellmanFordAlgorithm.h"

float BellmanFordAlgorithm::GetValueByEdgeNumber(FloatMatrix matrix, int n) {
  int v = matrix[0].size();
  int row = (int) n / v;
  return matrix[row][n - row * v - 1];
}

