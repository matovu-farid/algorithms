#ifndef online_judge
#include "store/print.h"
#endif

#include <iostream>
#include <vector>
using ll = long long int;

using namespace std;
long long int p = 31, mod = 1e9 + 7;

long long int poly_hash(string s) {
  long long int hash = 0;
  long long int p_power = 1;
  for (auto c : s) {
    hash += ((c - 'a' + 1) * p_power);
    p_power *= p;
    hash %= mod;
    p_power %= mod;
  }
  return hash;
}
long long int power(long long int a, int n) {
  long long int res = 1;
  while (n){
    if(n & 1) {
      res *= a;
      res %= mod;
    }
    a *= a;
    a %= mod;
    n >>= 1;
  }
  return res;
}
int inverse(int x){
  return power(x, mod - 2) % mod;
}
bool search(string s, string pattern) {
  int k = pattern.length();
  int patternHash = poly_hash(pattern);
  long long int hash = poly_hash(s.substr(0, k));
  auto p_inverse = inverse(p);
  auto p_power = power(p, k - 1) % mod;

  int i = 0;
  while (patternHash != hash and i + k - 1 < s.size()) {
    hash = (hash - (s[i] - 'a' + 1) + mod) % mod;
    i += 1;
    hash *= p_inverse;
    hash += ((s[i + k - 1] - 'a' + 1) * p_power);
    hash %= mod;
  }
  return patternHash == hash;
}
void solve() {
  string s = "ababcaba";
  string p = "ca";
  cout << search(s, p) << endl;
  cout << power(2, 3) << endl;
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
