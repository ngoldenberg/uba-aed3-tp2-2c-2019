#include "BellmanFordAlgorithm.h"

int BellmanFordAlgorithm::Solve(int const currencies_quantity, const FloatMatrix &matrix) {
  return 0;
}

tuple<int, int, float> BellmanFordAlgorithm::GetEdgeByNumber(FloatMatrix matrix, int n) {
  int v = matrix[0].size();
  int row = (int) n / v;
  int column = n - row * v - 1;
  if (row == column) return {row, column, 0};

  return {row, column, matrix[row][column]};
}

bool BellmanFordAlgorithm::CycleExists(int const currencies_quantity,
                                       const FloatMatrix &matrix,
                                       int src_vertex) {
  int vertices = currencies_quantity;
  int edges = vertices ^2;

  int dist[currencies_quantity];

  // Step 1: Initialize distances from src to all other vertices
  // as INFINITE
  for (int i = 0; i < vertices; i++)
    dist[i] = INT_MAX;
  dist[src_vertex] = 0;

  // Step 2: Relax all edges |V| - 1 times. A simple shortest
  // path from src to any other vertex can have at-most |V| - 1
  // edges
  for (int i = 1; i <= vertices - 1; i++) {
    for (int j = 0; j < edges; j++) {
      tuple<int, int, float> edge = GetEdgeByNumber(matrix, j + 1);
      if (get<2>(edge) != 0) {
        continue;
      }

      int src = get<0>(edge) + 1;
      int dest = get<1>(edge) + 1;
      float mult = get<2>(edge);
      if (dist[src] != INT_MAX && dist[src] + mult < dist[dest])
        dist[dest] = dist[src] + mult;
    }
  }

  // Step 3: check for negative-weight cycles.  The above step
  // guarantees shortest distances if graph doesn't contain
  // negative weight cycle.  If we get a shorter path, then there
  // is a cycle.
  for (int i = 0; i < edges; i++) {
    tuple<int, int, float> edge = GetEdgeByNumber(matrix, i + 1);
    if (get<2>(edge) != 0) {
      continue;
    }

    int src = get<0>(edge) + 1;
    int dest = get<1>(edge) + 1;
    float mult = get<2>(edge);

    if (dist[src] != INT_MAX && dist[src] + mult < dist[dest]) {
      printf("Graph contains negative weight cycle");
      throw logic_error("Negative cycle detected"); // If negative cycle is detected, simply return
    }
  }

}


void printArr(int dist[], int n)
{
  printf("Vertex   Distance from Source\n");
  for (int i = 0; i < n; ++i)
    printf("%d \t\t %d\n", i, dist[i]);
}

//// The main function that finds shortest distances from src to
//// all other vertices using Bellman-Ford algorithm.  The function
//// also detects negative weight cycle
//void BellmanFord(struct Graph *graph, int src) {
//  int V = graph->V;
//  int E = graph->E;
//  int dist[V];
//
//  // Step 1: Initialize distances from src to all other vertices
//  // as INFINITE
//  for (int i = 0; i < V; i++)
//    dist[i] = INT_MAX;
//  dist[src] = 0;
//
//  // Step 2: Relax all edges |V| - 1 times. A simple shortest
//  // path from src to any other vertex can have at-most |V| - 1
//  // edges
//  for (int i = 1; i <= V - 1; i++) {
//    for (int j = 0; j < E; j++) {
//      int u = graph->edge[j].src;
//      int v = graph->edge[j].dest;
//      int weight = graph->edge[j].weight;
//      if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
//        dist[v] = dist[u] + weight;
//    }
//  }
//
//  // Step 3: check for negative-weight cycles.  The above step
//  // guarantees shortest distances if graph doesn't contain
//  // negative weight cycle.  If we get a shorter path, then there
//  // is a cycle.
//  for (int i = 0; i < E; i++) {
//    int u = graph->edge[i].src;
//    int v = graph->edge[i].dest;
//    int weight = graph->edge[i].weight;
//    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
//      printf("Graph contains negative weight cycle");
//      return; // If negative cycle is detected, simply return
//    }
//  }
//
//  printArr(dist, V);
//
//  return;
//}