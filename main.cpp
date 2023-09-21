#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

using namespace std;
/* 
Total Hamming Distance
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.
*/
int count_bits(int n) {
  int count = 0;
  while (n) {
    n = n & (n - 1);
    count++;
  }
  return count;
}
int totalHammingDistance(vector<int> nums) {
  int res = 0;
  int n = nums.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int diff = (nums[i] ^ nums[j]);
      int distance = count_bits(diff);

      res += distance;
    }
  }
  return res;
}
void solve() {
  vector<int> nums = {4, 14, 2};
  cout << totalHammingDistance(nums);
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
