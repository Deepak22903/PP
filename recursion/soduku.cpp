#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool isValid(vector<vector<char>> &board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
      if (board[row][i] == num)
        return false;
      if (board[i][col] == num)
        return false;
      if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == num)
        return false;
    }
    return true;
  }
  bool sudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') {
          for (char c = '1'; c <= '9'; c++) {
            if (isValid(board, i, j, c)) {
              board[i][j] = c;
              if (sudoku(board))
                return true;
              board[i][j] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }

  void solveSudoku(vector<vector<char>> &board) {
    // Implementation goes here
    sudoku(board);
  }
};

int main() {
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  Solution sol;
  sol.solveSudoku(board);

  // Output the solved board
  for (const auto &row : board) {
    for (char c : row)
      cout << c << " ";
    cout << endl;
  }

  return 0;
}
