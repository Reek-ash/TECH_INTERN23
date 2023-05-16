#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int destination, weight;
};

// Structure to represent a node in the graph
struct Node {
    int vertex, weight;
};

// Comparison function for the priority queue
struct CompareNode {
    bool operator()(const Node& a, const Node& b) {
        return a.weight > b.weight;
    }
};

// Prim's algorithm to find minimum spanning tree
vector<Edge> primMST(vector<vector<Edge>>& graph, int numVertices) {
    vector<Edge> minimumSpanningTree;
    vector<bool> visited(numVertices, false);
    priority_queue<Node, vector<Node>, CompareNode> pq;
    
    // Start with vertex 0
    int startVertex = 0;
    visited[startVertex] = true;
    
    // Add all edges from the start vertex to the priority queue
    for (const auto& edge : graph[startVertex]) {
        pq.push({edge.destination, edge.weight});
    }
    
    // Process the remaining vertices
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        
        int currentVertex = node.vertex;
        
        // Skip if the vertex is already visited
        if (visited[currentVertex])
            continue;
        
        visited[currentVertex] = true;
        
        // Add the edge to the minimum spanning tree
        minimumSpanningTree.push_back({currentVertex, node.weight});
        
        // Add all adjacent edges to the priority queue
        for (const auto& edge : graph[currentVertex]) {
            if (!visited[edge.destination]) {
                pq.push({edge.destination, edge.weight});
            }
        }
    }
    
    return minimumSpanningTree;
}

int main() {
    int numVertices = 6;
    int numEdges = 9;
    
    vector<vector<Edge>> graph(numVertices);
    
    // Add edges to the graph
    graph[0].push_back({1, 4});
    graph[1].push_back({0, 4});
    graph[0].push_back({2, 3});
    graph[2].push_back({0, 3});
    graph[1].push_back({2, 1});
    graph[2].push_back({1, 1});
    graph[1].push_back({3, 2});
    graph[3].push_back({1, 2});
    graph[2].push_back({3, 4});
    graph[3].push_back({2, 4});
    graph[2].push_back({4, 2});
    graph[4].push_back({2, 2});
    graph[2].push_back({5, 3});
    graph[5].push_back({2, 3});
    graph[3].push_back({4, 3});
    graph[4].push_back({3, 3});
    graph[4].push_back({5, 4});
    graph[5].push_back({4, 4});
    
    vector<Edge> minimumSpanningTree = primMST(graph, numVertices);
    
    cout << "Minimum Spanning Tree:\n";
    for (const auto& edge : minimumSpanningTree) {
        cout << edge.destination << " - " << edge.weight << "\n";
    }
    
    return 0;
}
