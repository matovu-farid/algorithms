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

int unique_number_III(vector<int> &nums, int n) {
  
  int bits = 32;
  vector<int> num_bits(bits);
  for (int i = 0; i < bits; i++) {
    int mask = 1 << i;

    int count = 0;
    for (int num : nums) {
      if (num & mask)
        count++;
    }
    num_bits[i] = count % 3;
  }
  int num = 0;
  for(int i = 0; i < bits; i++){
    num +=  num_bits[i] * (1 << i);
  }
  return num;
}
void solve() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];

  int num = unique_number_III(nums, n);
  cout << num << endl;
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
