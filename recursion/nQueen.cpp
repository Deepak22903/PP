#include <iostream>
#include <vector>
using namespace std;

bool notAttacking(vector<string> &board, int row, int col) {
  int rowDup = row;
  int colDup = col;
  while (row >= 0 && col >= 0 && board[row][col] != 'Q') {
    row--;
    col--;
  }
  if (row >= 0 && col >= 0 && board[row][col] == 'Q')
    return false;
  row = rowDup;
  col = colDup;
  while (col >= 0 && board[row][col] != 'Q')
    col--;
  if (col >= 0 && board[row][col] == 'Q')
    return false;
  row = rowDup;
  col = colDup;
  while (row < board.size() && col >= 0 && board[row][col] != 'Q') {
    row++;
    col--;
  }
  if (row < board.size() && col >= 0 && board[row][col] == 'Q')
    return false;
  return true;
}

void nQueen(vector<string> &board, int col, int n,
            vector<vector<string>> &res) {

  if (col == n) {
    res.push_back(board);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (notAttacking(board, i, col)) {
      board[i][col] = 'Q';
      nQueen(board, col + 1, n, res);
      board[i][col] = '.';
    }
  }
}

int main(int argc, char *argv[]) {
  int n = 4;
  vector<string> board(n);
  string s(n, '.');
  for (int i = 0; i < n; i++)
    board[i] = s;
  vector<vector<string>> res;
  nQueen(board, 0, n, res);
  for (auto sol : res) {
    for (auto row : sol) {
      cout << row << endl;
    }
    cout << endl;
  }
  return 0;
}
