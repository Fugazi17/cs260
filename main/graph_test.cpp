#include "graph.hpp"
#include <iostream>

using std::endl;
using std::cout;
using std::vector;

void test_addVertex() {
    Graph graph;
    graph.addVertex("A");
    graph.addVertex("B");
    graph.addVertex("C");

    cout << "Vertices Added: A, B, C" << endl;
}

void test_addEdge() {
    Graph graph;
    graph.addVertex("A");
    graph.addVertex("B");
    graph.addVertex("C");
    graph.addEdge("A", "B", 2);
    graph.addEdge("B", "C", 3);
    graph.addEdge("A", "C", 4);

    cout << "Edges Added: (A, B), (B, C), (A, C)" << endl;
}

void test_shortestPath() {
    Graph graph;
    graph.addVertex("A");
    graph.addVertex("B");
    graph.addVertex("C");
    graph.addVertex("D");
    graph.addEdge("A", "B", 2);
    graph.addEdge("B", "C", 3);
    graph.addEdge("A", "C", 4);
    graph.addEdge("C", "D", 1);

    vector<const char*> path = graph.shortestPath("A", "D");

    cout << "Shortest Path from A to D: ";
    for (const auto& vertex : path) {
        cout << vertex << " ";
    }
    cout << endl;
}

void test_minSpanTree()
{
    Graph graph;
    graph.addVertex("A");
    graph.addVertex("B");
    graph.addVertex("C");
    graph.addVertex("D");
    graph.addEdge("A", "B", 2);
    graph.addEdge("B", "C", 3);
    graph.addEdge("A", "C", 4);
    graph.addEdge("C", "D", 1);

    vector<std::pair<const char*, const char*>> minSpanningTree = graph.minSpanTree();
}

int main()
{
    test_addVertex();
    test_addEdge();
    test_shortestPath();
    test_minSpanTree();

    return 0;
}
