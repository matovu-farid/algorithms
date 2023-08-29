#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int N = 1e5;
const int M = 20;

int parents[N][M];

int depth[N];
vector<int> graph[N];
void dfs(int curr, int parent) {
  parents[curr][0] = parent;
  depth[curr] = depth[parent] + 1;
  for (int j = 1; j < M; j++) {
    parents[curr][j] = parents[parents[curr][j - 1]][j - 1];
  }
  for (int neighbour : graph[curr]) {
    if (neighbour != parent) {
      dfs(neighbour, curr);
    }
  }
}
void initGraph(vector<vector<int>> edges) {
  for (auto edge : edges) {
    graph[edge[0]].push_back(edge[1]);
  }

}
vector<int> LCA(int n, vector<vector<int>> edges, vector<vector<int>> queries) {
  vector<int> res;
  initGraph(edges);
 
  depth[0] = -1;
  dfs(1, 0);
  for (auto query : queries) {
    int u = query[0];
    int v = query[1];
    if (u == v) {
      res.push_back(u);
      continue;
    }

    if (depth[u] < depth[v]) {
      swap(u, v);
    }
    int diff = depth[u] - depth[v];
    for (int i = M - 1; i >= 0; i--) {
      if (diff & (1 << i)) {
        u = parents[u][i];
      }
    }
    for (int i = M - 1; i >= 0; i--) {
      if (parents[u][i] != parents[v][i]) {
        u = parents[u][i];
        v = parents[v][i];
      }
    }
    int ans = parents[u][0];
    if (ans == 0)
      ans = 1;
    res.push_back(ans);
  }

  return res;
}
