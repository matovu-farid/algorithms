#include <climits>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

int tsp(vector<vector<int>>& dist, int visited, int city, int n,  vector<vector<int>>& memo){
  if(visited == (1 << n) - 1){
    return dist[city][0];
  }
  if(memo[visited][city] != -1) return memo[visited][city];

  int min_cost = INT_MAX;
  for (int next_city = 0; next_city < n; next_city++){
    if(visited & (1 << next_city)) continue;
    int cost = dist[city][next_city] + tsp(dist, visited | (1 << city), next_city, n, memo);
    min_cost = min(min_cost, cost);

  }
  memo[visited][city] = min_cost;
  return min_cost ;
}
void solve() {
  vector<vector<int>> dist = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}
  };
  int n = 4;
  vector<vector<int>> memo((1 << n), vector<int>(n, -1));
  int res = tsp(dist, 0, 0, n, memo);
  cout << res << endl;
  
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
