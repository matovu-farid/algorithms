// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#ifndef ONLINE_JUDGE
 #include "store/print.h"
#endif

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

vector<vector<int>> g;
vector<ll> leaf_count;


void dfs(int v, int p) {
  if (g[v].size() == 1 && g[v][0] == p) {
    leaf_count[v] = 1;
  } else {
    for (auto u : g[v]) {
      if (u != p) {
        dfs(u, v);
        leaf_count[v] += leaf_count[u];
      }
    }
  }
}

void solve() {
  int n, q;
  cin >> n;

  g.assign(n, vector<int>());
  g.reserve(n);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  leaf_count.assign(n, 0);
  leaf_count.reserve(n);
  dfs(0, -1);

  cin >> q;
  for (int i = 0; i < q; i++) {
    int c, k;
    cin >> c >> k;
    c--;
    k--;

    ll res = leaf_count[c] * leaf_count[k];
    cout << res << endl;
  }
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
