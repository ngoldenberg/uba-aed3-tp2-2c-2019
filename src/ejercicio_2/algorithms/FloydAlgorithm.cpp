#include "FloydAlgorithm.h"

vector<int> FloydAlgorithm::Solve(int const n, FloatMatrix const &matrix) {
  std::vector<std::vector<double>> dist;
  for(int iter = 0; iter < n; iter ++){
    dist.push_back(std::vector<double>(n));
  }

  int next[n][n];
  memset(next, 0, sizeof(next));

  for (uint i = 0; i < n; i++) {
    for (uint j = 0; j < n; j++) 
    { 
      dist[i][j] = -log(matrix[i][j]);
      next[i][j] = j;
     }
   }

  for (uint k = 0; k < n; k++) {
    for (uint i = 0; i < n; i++) {
      for (uint j = 0; j < n; j++) {
        double d = dist[i][k] + dist[k][j];
        if (dist[i][j] > d) {
          dist[i][j] = d;
          next[i][j] = next[i][k];
        }
      }
    }
  }

  if (dist[0][0] >= 0) {
    throw logic_error("No negative cycle detected");
  }

  vector<int> cycle;
  cycle.push_back(0);
  int s = 0;
  do{
      int t = next[s][0];
      cycle.push_back(GetEdgeNumberByAxis(matrix, s, t));
      s = t;
    }while(s != 0);
  
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
