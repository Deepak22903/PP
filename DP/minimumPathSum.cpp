#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int tabu(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
    for (int r = 0; r <= i; r++) {
      for (int c = 0; c <= j; c++) {
        if (r == 0 && c == 0)
          dp[r][c] = grid[r][c];
        else {
          int up = grid[r][c], left = grid[r][c];
          if (r > 0)
            up = grid[r][c] + dp[r - 1][c];
          else
            up = up + 1e9;
          if (c > 0)
            left = grid[r][c] + dp[r][c - 1];
          else
            left = left + 1e9;
          dp[r][c] = min(up, left);
        }
      }
    }
    return dp[i][j];
  }
  int f(vector<vector<int>> &grid, int r, int c, vector<vector<int>> &dp) {
    if (r < 0 || c < 0)
      return 1e9;
    if (r == 0 && c == 0) {
      return grid[0][0];
    }
    if (dp[r][c] != -1)
      return dp[r][c];
    int up = grid[r][c] + f(grid, r - 1, c, dp);
    int left = grid[r][c] + f(grid, r, c - 1, dp);
    return dp[r][c] = min(up, left);
  }

  int minPathSum(vector<vector<int>> &grid) {
    // implementation goes here
    int r = grid.size() - 1;
    int c = grid[0].size() - 1;
    vector<vector<int>> dp(r + 1, vector<int>(c + 1, -1));
    // return f(grid, r, c, dp);
    return tabu(grid, r, c, dp);
  }
};

int main() {
  Solution sol;

  vector<vector<vector<int>>> testCases = {
      {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, // expected: 7
      {{1, 2, 3}, {4, 5, 6}},            // expected: 12
      {{5}},                             // expected: 5
      {{1, 2}, {1, 1}},                  // expected: 3
      {{1, 2, 5}, {3, 2, 1}}             // expected: 6
  };

  for (size_t i = 0; i < testCases.size(); i++) {
    vector<vector<int>> grid = testCases[i];
    int result = sol.minPathSum(grid);
    cout << "Test case " << i + 1 << " -> Minimum Path Sum: " << result << endl;
  }

  return 0;
}
