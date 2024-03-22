#include <unordered_map>
#include <vector>

using std::vector;
using std::pair;

class Graph
{
private:
    std::unordered_map<const char*, vector<pair<const char*, int>>> adjList;

public:
    void addVertex(const char* vertexName);
    void addEdge(const char* source, const char* destination, int weight);
    vector<const char*> shortestPath(const char* source, const char* destination);
    vector<pair<const char*, const char*>> minSpanTree();
};