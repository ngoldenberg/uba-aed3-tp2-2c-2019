#include "BellmanFordAlgorithm.h"
#include "../config/constants.h"

vector<int> BellmanFordAlgorithm::Solve(int const currencies_quantity, const FloatMatrix &matrix) {
  for (int i = 0; i < currencies_quantity; i++) {
    for (int j = 0; i < currencies_quantity; i++) {
      if (j != i && matrix[i][j] > 1 && matrix[j][i] > 1) {
        return vector<int>{GetEdgeNumberByAxis(matrix, i, j), GetEdgeNumberByAxis(matrix, j, i)};
      }
    }
  } // O(n^2)

  return this->GetCycle(currencies_quantity, matrix, 1);
}

tuple<int, int, float> BellmanFordAlgorithm::GetEdgeByNumber(FloatMatrix matrix, int n) {
  int v = matrix[0].size();
  int row = (int) n / v;
  int column = n - row * v;
  if (row == column) return std::make_tuple(row, column, 0);

  return std::make_tuple(row, column, matrix[row][column]);
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

vector<int> BellmanFordAlgorithm::GetCycle(int const currencies_quantity,
                                           const FloatMatrix &matrix,
                                           int src_vertex) {
  int vertices = currencies_quantity;
  int edges = vertices * (vertices - 1);

  AdjList adj_list = this->GetAdjacencyList(matrix);
  vector<pair<float, int>> shortest_distances(vertices + 1);
  // shortest_distances is a vector of pairs
  // pair.first -> the shortest distance from start vertex
  // pair.second -> parent vertex in the shortest path

  list<pair<int, float> >::iterator
      traverse;
  int i, j;

  // Initialisation
  for (i = 0; i <= vertices; ++i) {
    shortest_distances[i].first = INT_MIN;
    shortest_distances[i].second = -1;
  }

  // Setting distance to source = 0
  shortest_distances[src_vertex].first = 1;
  shortest_distances[src_vertex].second = 0;

  // The Algorithm that computes Shortest Distances
  for (i = 1; i <= vertices - 1; ++i) {    // Runs 'vertices - 1' times = O(|V|)
    for (j = 1; j <= vertices; ++j) {    // Runs as many times as the edges = O(|E|)
      // The code ahead basically explores the whole of Adjacency List,
      // covering one edge once, so the runtime of the code in this
      // block is O(|E|)

      traverse = adj_list[j].begin();

      while (traverse != adj_list[j].end()) {

        if (shortest_distances[j].first == INT_MIN) {
          // Important...!
          //traverse = traverse->next;
          ++traverse;
          continue;
        }

        // Checking for Relaxation
        if ((*traverse).second * shortest_distances[j].first >
            shortest_distances[(*traverse).first].first) {
          // Relaxation
          shortest_distances[(*traverse).first].first = (*traverse).second
              * shortest_distances[j].first;
          shortest_distances[(*traverse).first].second = j;
        }

        ++traverse;
      }
    }
  }

  // Checking for Negative Cycles
  for (j = 1; j <= vertices; ++j) {
    traverse = adj_list[j].begin();
    while (traverse != adj_list[j].end()) {
      // Checking for further relaxation
      if ((*traverse).second * shortest_distances[j].first >
          shortest_distances[(*traverse).first].first) {
        // Negative Cycle found as further relaxation is possible
        vector<int> negative_cycle;
        this->GetNegativeCycle(shortest_distances, shortest_distances[j].second, j, negative_cycle);
        return negative_cycle;
      }

      ++traverse;
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

