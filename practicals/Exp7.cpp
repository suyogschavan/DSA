/* ================================================== 
 Description     : You have a business with several offices; you want to lease phone lines to connect them
up with each other; and the phone company charges different amounts of money to
connect different pairs of cities. You want a set of lines that connects all your offices
with a minimum total cost. Solve the problem by suggesting appropriate data structures.
 Author          : Suyog Chavan
 Reach me here   : https://suyogchavan.me 
 Date of creation: Wednesday, 17 May 2023 
 Copyright       : ©suyogschavan03@gmail.com
================================================== */

#include <iostream>
#include <vector>
#include <limits>

// Structure to represent an edge between two offices
struct Edge {
    int source;
    int destination;
    int weight;

    Edge(int source, int destination, int weight)
        : source(source), destination(destination), weight(weight) {}
};

// Function to find the minimum spanning tree using Prim's algorithm
std::vector<Edge> findMinimumSpanningTree(const std::vector<std::vector<int>>& graph) {
    int numOffices = graph.size();

    std::vector<Edge> minimumSpanningTree;
    std::vector<int> minWeight(numOffices, std::numeric_limits<int>::max());
    std::vector<bool> visited(numOffices, false);

    // Start with the first office as the initial vertex
    int startVertex = 0;
    minWeight[startVertex] = 0;

    // Process all vertices
    for (int count = 0; count < numOffices - 1; ++count) {
        // Find the vertex with the minimum weight
        int minVertex = -1;
        for (int v = 0; v < numOffices; ++v) {
            if (!visited[v] && (minVertex == -1 || minWeight[v] < minWeight[minVertex])) {
                minVertex = v;
            }
        }

        // Mark the selected vertex as visited
        visited[minVertex] = true;

        // Add the selected edge to the minimum spanning tree
        if (minVertex != startVertex) {
            minimumSpanningTree.push_back(Edge(minVertex, minVertex, minWeight[minVertex]));
        }

        // Update the minimum weight and corresponding edges of the adjacent vertices
        for (int v = 0; v < numOffices; ++v) {
            if (!visited[v] && graph[minVertex][v] != 0 && graph[minVertex][v] < minWeight[v]) {
                minWeight[v] = graph[minVertex][v];
            }
        }
    }

    return minimumSpanningTree;
}

int main() {
    int numOffices = 5;

    // Example graph representation (adjacency matrix)
    std::vector<std::vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    std::vector<Edge> minimumSpanningTree = findMinimumSpanningTree(graph);

    // Display the minimum spanning tree (phone lines)
    std::cout << "Minimum Spanning Tree (Phone Lines):" << std::endl;
    for (const Edge& edge : minimumSpanningTree) {
        std::cout << "Office " << edge.source << " - Office " << edge.destination << " (Cost: " << edge.weight << ")" << std::endl;
    }

    return 0;
}


