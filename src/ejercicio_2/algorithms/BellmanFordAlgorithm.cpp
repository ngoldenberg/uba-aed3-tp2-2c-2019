#include "BellmanFordAlgorithm.h"
#include "../config/constants.h"
#include "common/graph.h"
#include <vector>

vector<int> BellmanFordAlgorithm::Solve(int const currencies_quantity, const FloatMatrix &matrix) {
//  for (int i = 0; i < currencies_quantity; i++) {
//    for (int j = 0; j < currencies_quantity; j++) {
//      if (j != i && matrix[i][j] > 1 && matrix[j][i] > 1) {
//        return vector<int>{GetEdgeNumberByAxis(matrix, i, j), GetEdgeNumberByAxis(matrix, j, i)};
//      }
//    }
//  } // O(n^2)


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
//      cout << "PRINT src: " << i << " | dest: " << j <<" | w: " << matrix[i][j] << endl;
    }
  }

  return this->GetCycle(graph, 0, matrix);;
}

tuple<int, int, float> BellmanFordAlgorithm::GetEdgeByNumber(FloatMatrix matrix, int n) {
  int v = matrix[0].size();
  int row = (int) n / v;
  int column = n - row * v;
  if (row == column) return {row, column, 0};

  return {row, column, matrix[row][column]};
}

int BellmanFordAlgorithm::GetEdgeNumberByAxis(const FloatMatrix &matrix, int r, int c) {
  if (r == c) return 0;

  int v = matrix[0].size();

  if (c < r) {
    return r * (v - 1) + c + 1;
  }
  return r * (v - 1) + c;
}

AdjList BellmanFordAlgorithm::GetAdjacencyList(const FloatMatrix matrix) {
  int edges = matrix[0].size() * (matrix[0].size() - 1);
  AdjList adj_list(matrix[0].size() + 1);

  for (int j = 1; j < matrix[0].size() * matrix[0].size(); j++) {
    tuple<int, int, float> edge = GetEdgeByNumber(matrix, j);
    if (get<2>(edge) == 0) {
      continue;
    }
    // TODO: Check +1 usage
    pair<int, float> pr = {get<1>(edge) + 1, get<2>(edge)};
    adj_list[get<0>(edge) + 1].push_back(pr);
  }

  return adj_list;
}

vector<int> BellmanFordAlgorithm::GetCycle(struct Graph *graph, int src, const FloatMatrix &matrix) {
  int V = graph->V;
  int E = graph->E;
  float dist[V];

  // Step 1: Initialize distances from src to all other vertices
  // as INFINITE
  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX;
  dist[src] = 0;

  vector<int> pre(V, -1);

  // Step 2: Relax all edges |V| - 1 times. A simple shortest
  // path from src to any other vertex can have at-most |V| - 1
  // edges
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
  // Step 3: check for negative-weight cycles.  The above step
  // guarantees shortest distances if graph doesn't contain
  // negative weight cycle.  If we get a shorter path, then there
  // is a cycle.
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
        tmp.push_back(this->GetEdgeNumberByAxis(matrix, cycle[k], cycle[k+1]));
      }
      return tmp; // If negative cycle is detected, simply return
    }
  }

  throw logic_error("No negative cycle detected");
}

void BellmanFordAlgorithm::GetNegativeCycle(vector<pair<float, int>> const &shortest_distances,
                                            int vertex,
                                            int start_vertex, vector<int> &cycle) {
  if (cycle.size() >= shortest_distances.size()) {
    return;
  }

  if (vertex == start_vertex) {
    cycle.push_back(vertex);
  } else if (shortest_distances[vertex].second == 0) {
    cycle.push_back(vertex);
    GetNegativeCycle(shortest_distances, start_vertex, start_vertex, cycle);
  } else {
    cycle.push_back(vertex);
    GetNegativeCycle(shortest_distances, shortest_distances[vertex].second, start_vertex, cycle);
  }
}

bool BellmanFordAlgorithm::In(int n, vector<int> list) {
  for (int i = 0; i < list.size(); i++) {
    if (list[i] == n) return true;
  }
  return false;
}
