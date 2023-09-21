#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
#include <unordered_map>
using ll = long long;

/* 
 * Triples with Bitwise AND Equal To Zero
 * Given an integer array nums, return the number of AND triples.
 *
 * An AND triple is a triple of indices (i, j, k) such that:
 *
 * 0 <= i < nums.length
 *
 * 0 <= j < nums.length
 *
 * 0 <= k < nums.length
 *
 * nums[i] & nums[j] & nums[k] == 0, where & represents the bitwise-AND operator.
 */
using namespace std;
 
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> pairAnd;
        
        // Calculate AND for every pair and store in map
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                pairAnd[nums[i] & nums[j]]++;
            }
        }
 
        int ans = 0;
        // Iterate over the map and then over the list
        for(auto &[andResult, count] : pairAnd){
            for(int num : nums){
                if((andResult & num) == 0) {
                    ans += count;
                }
            }
        }
        return ans;
    }
void solve() {
  vector<int> nums = { 2,1,3 };
  cout << countTriplets(nums)<< endl;
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
