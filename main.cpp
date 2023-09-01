#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>

using namespace std;
void generate_brackets(int closing, int opening, string current = ""){
  if (closing == 0 and opening == 0 ){
    cout << current << endl;
    return;
  }
  if (opening < 0 || opening > closing) return;
  generate_brackets(closing - 1, opening, current + ')');
  generate_brackets(closing, opening - 1, current + '(');

}

void solve() {
  int n;
  cin >> n;
  generate_brackets(n, n);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
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
