#include "BellmanFordAlgorithm.h"
#include "common/graph.h"
#include <vector>

vector<int> BellmanFordAlgorithm::Solve(int const currencies_quantity, const FloatMatrix &matrix) {
  struct Graph
      *graph = createGraph(currencies_quantity, currencies_quantity * currencies_quantity - currencies_quantity);
  vector<vector<int>> recorder;

  for (uint i = 0; i < currencies_quantity; i++) {
    for (uint j = 0; j < currencies_quantity; j++) {
      if (i == j) {
        continue;
      }
      graph->edge[GetEdgeNumberByAxis(matrix, i, j) - 1].src = i;
      graph->edge[GetEdgeNumberByAxis(matrix, i, j) - 1].dest = j;
      graph->edge[GetEdgeNumberByAxis(matrix, i, j) - 1].weight = -log(matrix[i][j]);
    }
  }

  return this->GetCycle(graph, 0, matrix);;
}

int BellmanFordAlgorithm::GetEdgeNumberByAxis(const FloatMatrix &matrix, int r, int c) {
  if (r == c) return 0;
  int v = matrix[0].size();
  if (c < r) return r * (v - 1) + c + 1;
  return r * (v - 1) + c;
}

vector<int> BellmanFordAlgorithm::GetCycle(struct Graph *graph, int src, const FloatMatrix &matrix) {
  int V = graph->V;
  int E = graph->E;
  float dist[V];

  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX;
  dist[src] = 0;

  vector<int> pre(V, -1);

  for (int i = 1; i <= V - 1; i++) {
    for (int j = 0; j < E; j++) {
      int v = graph->edge[j].src;
      int u = graph->edge[j].dest;
      float weight = graph->edge[j].weight;
      if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        pre[v] = u;
      }
    }
  }

  vector<int> cycle;
  for (int i = 0; i < E; i++) {
    int v = graph->edge[i].src;
    int u = graph->edge[i].dest;
    float weight = graph->edge[i].weight;
    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
      cycle.push_back(v);
      cycle.push_back(u);
      while (!this->In(pre[u], cycle)) {
        cycle.push_back(pre[u]);
      }
      vector<int> tmp;
      for (int k = 0; k < cycle.size(); k++) {
        tmp.push_back(this->GetEdgeNumberByAxis(matrix, cycle[k], cycle[k + 1]));
      }
      return tmp; // Return list of edges by number
    }
  }
  throw logic_error("No negative cycle detected");
}

bool BellmanFordAlgorithm::In(int n, vector<int> list) {
  for (int i : list)
    if (i == n) return true;
  return false;
}
