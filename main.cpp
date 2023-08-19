#include <climits>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>
#include "store/print.h"
using namespace std;

vector<int> dp(100000, -1);



int grundy(int n) {
  if (n == 0) return 0;
  if (dp[n] != -1) return dp[n];
  set<int> values;
  for (int i = n - 1; i >= max(n - 3, 0); i--){
    values.insert(grundy(i));
  }

  int mex = 0;
  while(values.find(mex) != values.end())
    mex += 1;
  dp[n] = mex;
  return mex;

}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("output.txt", "w", stderr);
  string s, key;
  std::getline(std::cin, s);
  std::getline(std::cin, key);
  
  vector<int> v = {1,1, 2, 3, 4, 5};
  vector<string> m = {"a", "b", "c", "d"};
  vector<vector<string>>n(5,m);
  vector<vector<vector<string>>>x(5,n);
  map<string, int> mp = {
    {"farid", 1},
    {"matovu", 2},
    {"nkoba", 3}
  };
  set<int> st(v.begin(), v.end());
  print(m);
  print(v);
  print(n);
  print(st);
  print(mp);
  print(x);

  return 0;
}
