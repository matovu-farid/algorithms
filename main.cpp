#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

/* Given 2N + 1 numbers, all the numbers are seen twice in the array exept one
 * (unique number). Find this unique number
 */
int unique_number(vector<int> &nums) {
  int ans = 0;
  for (int num : nums)
    ans ^= num;
  return ans;
}
void solve() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  cout << unique_number(nums) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
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
