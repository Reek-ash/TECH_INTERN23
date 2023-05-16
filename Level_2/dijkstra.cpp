#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define INF INT_MAX

// Graph class
class Graph {
    int V; // number of vertices
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void dijkstra(int source);
};

// Constructor
Graph::Graph(int V) {
    this->V = V;
    adjList.resize(V);
}

// Add an edge to the graph
void Graph::addEdge(int u, int v, int weight) {
    adjList[u].push_back(make_pair(v, weight));
    adjList[v].push_back(make_pair(u, weight));
}

// Dijkstra's algorithm implementation
void Graph::dijkstra(int source) {
    // Create a priority queue of pairs (vertex, distance)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Create a vector for distances and initialize it with infinity
    vector<int> dist(V, INF);

    // Insert the source vertex into the priority queue with distance 0
    pq.push(make_pair(0, source));
    dist[source] = 0;

    // Loop until the priority queue is empty
    while (!pq.empty()) {
        int u = pq.top().second; // Extract the vertex with the smallest distance
        pq.pop();

        // Iterate through all adjacent vertices of u
        for (auto i = adjList[u].begin(); i != adjList[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;

            // If a shorter path to v is found, update the distance and push it into the priority queue
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Print the shortest distances from the source to all vertices
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; ++i) {
        cout << i << "\t" << dist[i] << "\n";
    }
}

// Main function
int main() {
    int V = 9; // Number of vertices
    Graph g(V);

    // Add edges to the graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int source = 0; // Source vertex

    g.dijkstra(source);

    return 0;
}
