#include <algorithm>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

/*
 Sort Integers by The Number of 1 Bits
Given an integer array arr. You have to sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the sorted array.
*/
using namespace std;
int count_bits(int n) {
  int count = 0;
  while (n) {
    n = n & (n - 1);
    count++;
  }
  return count;
}
vector<int> sortByBits(vector<int> arr) {
  int n = arr.size();
  vector<int> res;
  vector<vector<int>> buckets(30);
  for (int num : arr) {
    int bit_count = count_bits(num);
    buckets[bit_count].push_back(num);
  }
  for (auto bucket : buckets) {
    sort(bucket.begin(), bucket.end());
    for (int num : bucket)
      res.push_back(num);
  }
  return res;
}

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<int> sorted_array = sortByBits(arr);
  print(sorted_array);
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
