#include <unordered_set>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, int n,const vector<int> graph[], unordered_set<int>& visited){
  if (visited.find(node) != visited.end()) return false;
  visited.insert(node);
  if (visited.size() == n) return true;
  for (int neighbour: graph[node]){
    if (visited.find(neighbour) != visited.end()) continue;
    if (dfs(neighbour,n, graph, visited)) return true;
  }
  visited.erase(node);
  return false;
}
bool isHamiltonPath(vector<int> graph[], int n){
  unordered_set<int> visited;
  for (int node = 0; node < n; node++){
    if (dfs(node,n, graph, visited)) return true;
  }
  return false;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> graph[n];
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);

  }
  cout <<isHamiltonPath(graph, n) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tests;
  cin >> tests;
  while (tests--) {
    solve();
  }

  return 0;
}
