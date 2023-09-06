#include <climits>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

int max_amount(int n, int nums[]){
  int dp[n + 1];
  dp[0] = 0;
  dp[1] = nums[0];
  for (int i = 2; i <= n; i++){
    dp[i] = nums[i - 1];
    for (int j = 1; j < i; j++){
      dp[i] = max(dp[i], (nums[j - 1] + dp[i - j]));
    }
  }
  return dp[n];

}
void solve() {
  int n;
  cin >> n;
  int nums[n];
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  cout << max_amount(n, nums) << endl;

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
