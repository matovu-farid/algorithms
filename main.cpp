#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;




struct Edge {
    int from, to, weight;
};

bool bellmanFord(const vector<Edge>& edges, int numVertices, int source, vector<int>& distance) {
    distance = vector<int>(numVertices, INT_MAX);
    distance[source] = 0;

    // Relax edges repeatedly
    for (int i = 1; i <= numVertices - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.from;
            int v = edge.to;
            int weight = edge.weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for (const auto& edge : edges) {
        int u = edge.from;
        int v = edge.to;
        int weight = edge.weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            // Negative weight cycle detected
            return false;
        }
    }

    return true;
}

void solve() {
    // Define the graph using edges (from, to, weight)
    vector<Edge> edges = {
        {0, 1, 1},
        {0, 2, -14},
        {1, 2, 2},
        {1, 3, 7},
        {2, 4, 3},
        {4, 3, 5},
        {3, 4, 2}
    };

    int numVertices = 5;
    int source = 0;
    vector<int> distance;

    if (bellmanFord(edges, numVertices, source, distance)) {
        cout << "Shortest distances from vertex " << source << ":\n";
        for (int i = 0; i < distance.size(); ++i) {
            cout << "Distance to vertex " << i << ": ";
            if (distance[i] == INT_MAX) {
                cout << "infinity";
            } else {
                cout << distance[i];
            }
            cout << endl;
        }
    } else {
        cout << "Negative weight cycle detected!\n";
    }

}


int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();

  return 0;
}
