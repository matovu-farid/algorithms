#include <algorithm>
#include <climits>
#include <unordered_map>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;
const int N = 1e5;

// https://www.spoj.com/problems/ABA12C/

int get_apples(int k, unordered_map<int, int> &apples
              ) {
  vector<int> dp(k + 1,N);
  dp[0] = 0;
  for (int i = 1; i <= k; i++){
    for(auto x: apples){
       int weight = x.first;
       int price = x.second;
      if(i >= weight){
        dp[i] = min(dp[i],price + dp[i - weight]); 
      }

    }
  }
  if(dp[k] == N) return -1;
  return dp[k];
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> apples;
  unordered_map<int, int> map;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    if (x == -1)
      continue;
    map[i + 1] = x;
  }

  cout << get_apples(k, map) << endl;
 
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
