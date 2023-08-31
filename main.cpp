// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

template<typename T>
struct fenwick {
  vector<T> tree;
  T n;
  fenwick(T n) {
    this->n = n + 1;
    tree.resize(this->n, 0);
  }
  fenwick(T n, vector<T>& v) {
    this->n = n + 1;
    tree.resize(this->n, 0);
    for (T i = 1; i < this->n; i++)
      update(i, v[i - 1]);
  }
  void update(T idx, T val){
    while (idx < n){
      tree[idx] += val;
      idx += (idx & -idx);
    }
  }
  T query(T idx){
    T res = 0;

    while (idx > 0 ){
      res += tree[idx];
      idx -= (idx & -idx);
    }
     return res;
  }
  T query_range(T l, T r) { return query(r) - query(l - 1); }

}; 

vector<int> nums;



void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    nums.push_back(a);
  }
   fenwick<int> tree(n, nums); 

  int q;
  cin >> q;
  while (q--) {
    int l;
    int r;
    cin >> l >> r;
    int v = tree.query_range(l, r);
    cout << v << endl;
  }
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
