#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int source) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);  // Initialize distances to "infinity"
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int dist_u = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Ignore outdated entries in priority queue
        if (dist_u > distance[u]) continue;

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            // Relaxation step
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}



void solve() {
// Define graph as an adjacency list: graph[u] contains pairs (v, w) such that there is an edge from u to v with weight w
    vector<vector<pair<int, int>>> graph = {
        {{1, 2}, {2, 4}},  // neighbors of vertex 0
        {{2, 1}, {3, 7}},  // neighbors of vertex 1
        {{3, 5}},          // neighbors of vertex 2
        {{4, 1}},          // neighbors of vertex 3
        {}                // neighbors of vertex 4
    };

    int source = 0;
    vector<int> distance = dijkstra(graph, source);

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
