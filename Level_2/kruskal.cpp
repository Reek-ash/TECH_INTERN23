#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int source, destination, weight;
};

// Structure to represent a disjoint set
struct DisjointSet {
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        
        // Initially, all vertices are in separate sets
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    
    // Find the root of a set
    int find(int vertex) {
        if (vertex != parent[vertex])
            parent[vertex] = find(parent[vertex]);
        return parent[vertex];
    }
    
    // Perform union of two sets
    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

// Comparison function for sorting edges based on weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Kruskal's algorithm to find minimum spanning tree
vector<Edge> kruskalMST(vector<Edge>& edges, int numVertices) {
    vector<Edge> minimumSpanningTree;
    DisjointSet disjointSet(numVertices);
    
    // Sort the edges in ascending order of weight
    sort(edges.begin(), edges.end(), compareEdges);
    
    // Process each edge in the sorted order
    for (const auto& edge : edges) {
        int sourceRoot = disjointSet.find(edge.source);
        int destinationRoot = disjointSet.find(edge.destination);
        
        // If including the current edge does not create a cycle, add it to the minimum spanning tree
        if (sourceRoot != destinationRoot) {
            minimumSpanningTree.push_back(edge);
            disjointSet.Union(sourceRoot, destinationRoot);
        }
    }
    
    return minimumSpanningTree;
}

int main() {
    int numVertices = 6;
    int numEdges = 9;
    
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 3},
        {1, 2, 1},
        {1, 3, 2},
        {2, 3, 4},
        {2, 4, 2},
        {2, 5, 3},
        {3, 4, 3},
        {4, 5, 4}
    };
    
    vector<Edge> minimumSpanningTree = kruskalMST(edges, numVertices);
    
    cout << "Minimum Spanning Tree:\n";
    for (const auto& edge : minimumSpanningTree) {
        cout << edge.source << " - " << edge.destination << " : " << edge.weight << "\n";
    }
    
    return 0;
}
