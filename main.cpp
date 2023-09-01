#include <cstdio>
#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 100;
int board[N][N];
const int QUEEN = 1;
const int BLANK = 0;

void printBoard(int n) {
  unordered_map<int, string> map = {{1 , "👑"} ,{0 , "🟩"}};

  for (int r = 0; r < n; r++) {
    for (int c = 0; c < n; c++) {
      cout << map[board[r][c]] << " ";
    }
    cout << endl;
  }
  cout << endl;
}
bool canPlace(int r, int c, int n) {
  for (int i = 0; i < n; i++)
    if (board[r][i] == QUEEN )
      return false;

  for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    if (board[i][j] == QUEEN)
      return false;

  for (int i = r, j = c; i < n && j >= 0; i++, j--)
    if (board[i][j] == QUEEN)
      return false;

  return true;
}
void getAllValidConfigs(int col, int n,int* count, int limit=4) {
  if (*count >= limit) return;
  if (col == n) {
    printBoard(n);
    (*count) += 1;
    return ;
  }
  for (int row = 0; row < n; row++) {
    if (!canPlace(row, col, n))
      continue;

    board[row][col] = QUEEN;
    getAllValidConfigs(col + 1, n,count, limit);
    board[row][col] = BLANK;
  }
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      board[i][j] = BLANK;
    }
  }
  int count = 0;
  int *countPointer = &count;
  getAllValidConfigs(0, n, countPointer, 5);
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
