#include "store/print.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
int solve(int n, vector<int> &primes) {
  int m = primes.size();
  vector<int> indices( m, 0);
  vector<long long> next_values(primes.begin(), primes.end());
  vector<int> dp( n, 0);
  dp[0] = 1;
  for (int i = 1; i < n; i++){
    dp[i] = *min_element(next_values.begin(), next_values.end());
    for (int j = 0; j < m; j++){
      if(dp[i] == next_values[j]){
        indices[j] += 1;
        next_values[j] = dp[indices[j]] * primes[j];
      }
    }
  }
  
  return dp[n - 1];
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("output.txt", "w", stderr);
  int n, d;
  cin >> n;
  cin >> d;
  vector<int> primes;
  for (int i = 0; i < d; i++) {
    int x;
    cin >> x;
    primes.push_back(x);
  }
  cout << solve(n, primes) << endl;
}
