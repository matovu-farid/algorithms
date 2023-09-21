#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

int matrixScore(vector<vector<int>> grid) {
  int n = grid.size(), m = grid[0].size();
  for (int i = 0; i < n; i++){
    if(grid[i][0] == 0){
      for (int j = 0; j < m; j++)
        grid[i][j] ^= 1;
    }
  }
  vector<int> counts(m,0);
  for (int j = 0; j < m; j++){
    for(int i = 0; i < n; i++){
      if(grid[i][j] == 1){
        counts[j]++;
      }
    }
  }
  for(int j = 0; j < m; j++){
    if(counts[j] > (n / 2)) continue;
    for(int i = 0; i < n; i++)
      grid[i][j] ^= 1;
  }
  int total = 0;
  for(int i = 0; i < n; i++){
    int num = 0;
    for (int j = 0; j < m; j++){
      int k = m - j - 1;

      num += grid[i][j] * (1 << k);
    }
    total += num;
  }
  
  return total;
    
}
void solve() {
  vector<vector<int>> grid = {{0,0,1,1},{ 1,0,1,0 },{ 1,1,0,0 }};
  int score = matrixScore(grid);
  cout << score << endl;
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
