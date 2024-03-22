#include "graph.hpp"
#include <queue>
#include <limits>
#include <cstring>

using std::vector;
using std::unordered_map;
using std::pair;
using std::make_pair;

void Graph::addVertex(const char* vertexName)
{
    if (adjList.find(vertexName) == adjList.end())
    {
        adjList[vertexName] = vector<pair<const char*, int>>();
    }
}

void Graph::addEdge(const char* source, const char* destination, int weight)
{
    addVertex(source);
    addVertex(destination);
    adjList[source].push_back(make_pair(destination, weight));
    adjList[destination].push_back(make_pair(source, weight)); // Assuming undirected graph
}

vector<const char*> Graph::shortestPath(const char* source, const char* destination)
{
    unordered_map<const char*, int> distance;
    unordered_map<const char*, const char*> parent;
    std::priority_queue<pair<int, const char*>, vector<pair<int, const char*>>, std::greater<pair<int, const char*>>> pq;

    for (const auto& entry : adjList)
    {
        distance[entry.first] = std::numeric_limits<int>::max();
    }

    distance[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        const char* u = pq.top().second;
        pq.pop();

        for (const auto& neighbor : adjList[u])
        {
            const char* v = neighbor.first;
            int weight = neighbor.second;

            if (distance[v] > distance[u] + weight)
            {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    vector<const char*> path;
    const char* current = destination;
    while (current != source)
    {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(source);

    vector<const char*> reversedPath;
    for (int i = path.size() - 1; i >= 0; --i)
    {
        reversedPath.push_back(path[i]);
    }

    return reversedPath;
}

vector<pair<const char*, const char*>> Graph::minSpanTree()
{
    return vector<pair<const char*, const char*>>();
}
