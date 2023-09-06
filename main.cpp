#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long;

// https://codeforces.com/problemset/problem/1091/D
using namespace std;
vector<ll> dp(1e5, 0);


const int MOD = 998244353;
long long fact(int n){
  if(dp[n]) return dp[n];

  if (n <= 1) return 1;
  dp[n] =  (n * fact(n - 1)) % MOD;
  return dp[n];

}
ll power(int n, int p){
  if(p == 0) return 1;
  if(p == 1) return n;
  if (p & 1) return (n * power(n , p - 1)) % MOD;
  ll temp  = (power(n, p / 2)) % MOD;
  return (temp * temp) % MOD;

}
void solve() {
  int n;
  cin >> n;
  dp.resize(n + 1, 0);
  ll total = (n * fact(n)) % MOD ;
  ll decreasingSuffixes = 0;
  for(int k = 1; k < n; k ++){
    decreasingSuffixes += ((fact(n) * power(fact(k), MOD - 2))) % MOD ;

  }
  decreasingSuffixes %= MOD;
  ll res = (total - decreasingSuffixes + MOD) % MOD;
  cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);


    solve();
  return 0;
}
