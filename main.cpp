#include <utility>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

int knapsack(vector<pair<int, int>> items, int N, int S) {
  vector<int> dp(S + 1, 0);
  for (int i = 1; i <= N; i++) {
    for (int j = S; j >= 0; j--) {
      auto item = items[i - 1];
      if (j - item.first >= 0)
        dp[j] = max(dp[j], dp[j - item.first] + item.second);
    }
  }
  return dp[S];
}

void solve() {
  int S, N;
  cin >> S >> N;
  vector<pair<int, int>> items(N);
  for (int i = 0; i < N; i++) {
    cin >> items[i].first >> items[i].second;
  }
  cout << knapsack(items, N, S) << endl;

 
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
