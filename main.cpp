#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>

using namespace std;

void findSubsets(string s, int n) {
  
  for (int mask = 0; mask < (1 << n); mask++ ){
    string subset = "";
    for (int i = 0; i < n; i++){
      if (mask & (1 << i)){
        subset += s[i];
      }
    }
    cout << subset << " ";
  }
  cout << endl;
}

void solve() {
  string s;
  cin >> s;
  const int n = s.length();
  
  findSubsets(s, n);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int tests;
  cin >> tests;
  while (tests--) {
    solve();
  }

  return 0;
}
