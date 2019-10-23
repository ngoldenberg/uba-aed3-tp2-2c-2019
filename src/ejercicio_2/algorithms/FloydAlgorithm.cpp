#include "FloydAlgorithm.h"

vector<int> FloydAlgorithm::Solve(int const n, FloatMatrix const &matrix) {
  double dist[n][n] = {0};
  int pred[n][n];
  memset(pred, 0, sizeof(pred));

  for (uint i = 0; i < n; i++) {
    for (uint j = 0; j < n; j++) {
      dist[i][j] = log(matrix[i][j]);
      pred[i][j] = i;
    }
  }

  for (uint k = 0; k < n; k++) {
    for (uint i = 0; i < n; i++) {
      for (uint j = 0; j < n; j++) {
        double d = dist[i][k] + dist[k][j];
        if (d > dist[i][j]) {
          dist[i][j] = d;
          pred[i][j] = pred[k][j];
        }
      }
    }
  }

  if (dist[0][0] <= 0) {
    throw logic_error("No negative cycle detected");
  }

  vector<int> cycle;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == pred[0][j])
        cycle.push_back(matrix[i][j] + 1);
    }
  }

  return cycle;
}