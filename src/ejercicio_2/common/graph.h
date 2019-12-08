struct Edge {
  int src, dest;
  float weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph {
  // V-> Number of vertices, E-> Number of edges
  int V, E;

  // graph is represented as an array of edges.
  struct Edge *edge;
};

// Creates a graph with V vertices and E edges
struct Graph *createGraph(int V, int E) {
  struct Graph *graph = new Graph;
  graph->V = V;
  graph->E = E;
  graph->edge = new Edge[E];
  return graph;
}

void printGraph(Graph* graph, int E) {
  for (int i = 0; i < E; i++) {
    std::cout << "-- \n";
    std::cout << "Edge: " << i << " \n";
    std::cout << "Src: " << graph->edge[i].src << " | Dest: " << graph->edge[i].dest << " | W: " << graph->edge[i].weight
         << endl;
    std::cout << "-- \n";
  }
}

// A utility function used to print the solution
void printArr(float dist[], int n) {
  printf("Vertex   Distance from Source\n");
  for (int i = 0; i < n; ++i)
    printf("%d \t\t %d\n", i, dist[i]);
}

// A utility function used to print the solution
void printArrInt(vector<int> dist, int n) {
  printf("Vertex   Distance from Source\n");
  for (int i = 0; i < n; ++i)
    printf("%d \t\t %d\n", i, dist[i]);
}