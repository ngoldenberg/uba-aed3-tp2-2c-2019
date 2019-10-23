#include "FloydAlgorithm.h"

vector<int> FloydAlgorithm::Solve(int const n, FloatMatrix const &matrix) {
  double dist[n][n] = {0};
  int pred[n][n];
  memset(pred, 0, sizeof(pred));

  for (uint i = 0; i < n; i++) {
    for (uint j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      dist[i][j] = log(matrix[i][j]);
      pred[i][j] = i;
    }
  }

  for (uint k = 0; k < n; k++) {
    for (uint i = 0; i < n; i++) {
      for (uint j = 0; j < n; j++) {
        if (k == j || k == i) {
          continue;
        }
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
        cycle.push_back(GetEdgeNumberByAxis(matrix, i, j));
    }
  }

  return cycle;
}

int FloydAlgorithm::GetEdgeNumberByAxis(const FloatMatrix &matrix, int r, int c) {
  if (r == c) return 0;

  int v = matrix[0].size();

  if (c < r) {
    return r * (v-1) + c + 1;
  }
  return r * (v-1) + c;
}
