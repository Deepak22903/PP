#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void nQueen(vector<string> &board, int col, int n,
            unordered_map<int, int> &leftRow,
            unordered_map<int, int> &upperDiagonal,
            unordered_map<int, int> &lowerDiagonal,
            vector<vector<string>> &res) {
  if (col == n) {
    res.push_back(board);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (leftRow.find(i) == leftRow.end() &&
        upperDiagonal.find(i + col) == upperDiagonal.end() &&
        lowerDiagonal.find(n - 1 + col - i) == lowerDiagonal.end()) {
      leftRow[i] = 1;
      upperDiagonal[i + col] = 1;
      lowerDiagonal[n - 1 + col - i] = 1;
      board[i][col] = 'Q';
      nQueen(board, col + 1, n, leftRow, upperDiagonal, lowerDiagonal, res);
      board[i][col] = '.';
      leftRow.erase(i);
      upperDiagonal.erase(i + col);
      lowerDiagonal.erase(n - 1 + col - i);
    }
  }
}

int main() {
  int n = 4;
  vector<string> board(n);
  string s(n, '.');
  for (int i = 0; i < board.size(); i++)
    board[i] = s;
  unordered_map<int, int> leftRow;
  unordered_map<int, int> upperDiagonal;
  unordered_map<int, int> lowerDiagonal;
  vector<vector<string>> res;
  nQueen(board, 0, n, leftRow, upperDiagonal, lowerDiagonal, res);
  for (auto it : res) {
    for (auto str : it) {
      cout << str << endl;
    }
    cout << endl;
  }
}
