#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>

using namespace std;

const int N = 100;
string board[N][N];
const string QUEEN = "👑";
const string BLANK = "🟩";

void printBoard(int n){
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        cout << board[r][c] << " ";
      }
      cout << endl;
    }
    cout << endl;
}
bool canPlace(int r, int c, int n) {
  for (int i = 0; i < n; i++) 
    if (board[r][i] == QUEEN || board[i][c] == QUEEN) return false;
  
  for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) 
    if (board[i][j] == QUEEN) return false;
  
  for (int i = r, j = c; i < n && j >= 0; i++, j--) 
    if (board[i][j] == QUEEN) return false;
  
  return true;
}

void getAllValidConfigs(int i, int n) {
  if (i == n) {
    printBoard(n);
    return;
  }
  for (int r = 0; r < n; r++) {
    if (!canPlace(r, i, n)) 
      continue;
    
    board[r][i] = QUEEN;
    getAllValidConfigs(i + 1, n);
    board[r][i] = BLANK;
  }
}

using namespace std;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      board[i][j] = BLANK;
    }
  }
  getAllValidConfigs(0, n);
  cout << endl;
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
