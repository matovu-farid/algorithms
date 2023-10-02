#include <utility>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

int knapsack(vector<pair<int, int>> items, int N, int S){
  vector<vector<int>> dp(N+1, vector<int>(S + 1, 0));
  for (int i = 1; i <= N; i++ ){
    for (int j = 0; j <= S; j++){
      dp[i][j] = dp[i - 1][j];
      auto item = items[i - 1];
      if(j - item.first >= 0){
       
        dp[i][j] = max(dp[i][j], dp[i - 1][j - item.first] + item.second);
      }

    }
  }
  return dp[N][S];
}

void solve() {
  int S, N;
  cin >> S >> N;
  vector<pair<int, int>> items(N);
  for (int i = 0; i < N; i++) {
    cin >> items[i].first >> items[i].second;
  }
  cout << knapsack(items, N,  S) << endl;
  
  // for(auto p: items) {
  //   print(p);
  //   cout << endl;
  // }
  
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
