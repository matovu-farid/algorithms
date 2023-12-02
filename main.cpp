#ifndef online_judge
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;
void dfs(int node, int endNode, vector<vector<int>> &g, vector<int> &path,
         vector<vector<int>> &res) {

  path.push_back(node);
  if (node == endNode) {
    res.push_back(path);
  }
  for (int nbr : g[node]) {
    dfs(nbr, endNode, g, path, res);
  }

  path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> graph) {
  int n = graph.size();
  vector<vector<int>> res;
  vector<int> path;

  dfs(0, n - 1, graph, path, res);
  return res;
}
void solve() {
  vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
  auto res = allPathsSourceTarget(graph);
  for (auto v : res) {
    for (auto i : v) {
      cout << i << " ";
    }
    cout << endl;
  }
}
int main() {
#ifndef ONLINE_JUDGE
  freopen(".input", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();

  return 0;
}
