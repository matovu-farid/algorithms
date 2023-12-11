#ifndef online_judge
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;
/**
  *
You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and
lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be
formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any
order. Example 1:

Injut: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].
Example 2:

Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
*/
typedef vector<int> vii;
class Solution {
public:
  static bool comparator(vii a, vii b) {
    if (a[1] == b[1])
      return a[0] < b[0];
    return a[1] < b[1];
  }
  int findLongestChain(vector<vii> &pairs) {
    sort(pairs.begin(), pairs.end(), comparator);
    int res = 1;
    int last = pairs[0][1];
    for (int i = 1; i < pairs.size(); ++i) {
      if (last < pairs[i][0]) {
        res += 1;
        last = pairs[i][1];
      }
    }
    return res;
  }
};
using namespace std;
void solve() {
  // vector<vector<int>> pairs = {{1, 2}, {7, 8}, {4, 5}};
  // vector<vector<int>> pairs = {{1, 2}, {7, 8}, {4, 5}};
  vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};

  Solution s;
  cout << s.findLongestChain(pairs) << endl;
}
int main() {
#ifndef ONLINE_JUDGE
  freopen(".input", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();

  return 0;
}
