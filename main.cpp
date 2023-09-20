#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;

/* Given 2N + 2 numbers, all the numbers are seen twice in the array exept two
 * (unique number). Find those two number
 */

vector<int> unique_number_II(vector<int> &nums, int n) {
  int total_diff = 0;
  for (int num : nums)
    total_diff ^= num;
  int pos = 0;
  int temp = total_diff;
  while (!(temp & 1)) {
    temp >>= 1;
    pos++;
  }
  int mask = 1 << pos;
  int num1 = 0;

  for (int num : nums)
    if (mask & num)
      num1 ^= num;

  int num2 = total_diff ^ num1;
  return {num1, num2};
}
void solve() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  vector<int> uni = unique_number_II(nums, n);
  print(uni);
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
