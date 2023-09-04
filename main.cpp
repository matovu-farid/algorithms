#ifndef ONLINE_JUDGE
#include "store/print.h"
#endif

#include <iostream>
#include <vector>

using namespace std;
const int N = 9;
int board[N][N];

void printBoard() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

bool canPlace(int row, int col, int num) {
  for (int i = 0; i < N; i++)
    if (board[i][col] == num || board[row][i] == num)
      return false;
  int rowIdx = row / 3;
  int colIdx = col / 3;
  int startRow = rowIdx * 3;
  int startCol = colIdx * 3;
  for (int i = startRow; i < startRow + 3; i++)
    for (int j = startCol; j < startCol + 3; j++)
      if (board[i][j] == num)
        return false;
  return true;
}
bool solveSudoku(int row, int col) {
  if (row == N)
    return true;

  if (col == N)
    return solveSudoku(row + 1, 0);

  if (board[row][col])
    return solveSudoku(row, col + 1);

  for (int num = 1; num <= N; num++) {
    if (!canPlace(row, col, num))
      continue;
    board[row][col] = num;
    if (solveSudoku(row, col + 1))
      return true;
    board[row][col] = 0;
  }
  return false;
}

void solve() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }
  solveSudoku(0, 0);
  printBoard();
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
