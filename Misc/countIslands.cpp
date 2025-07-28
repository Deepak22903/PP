#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  long long dfs(int i, int j, vector<vector<int>> &grid, vector<int> &drow,
                vector<int> &dcol, int m, int n, vector<vector<int>> &visited) {
    visited[i][j] = true;
    long long sum = grid[i][j];
    for (int d = 0; d < 4; d++) {
      int row = i + drow[d];
      int col = j + dcol[d];
      if (row < n && row >= 0 && col < m && col >= 0 && grid[row][col] != 0 &&
          !visited[row][col]) {
        sum += dfs(row, col, grid, drow, dcol, m, n, visited);
      }
    }
    return sum;
  }
  int countIslands(vector<vector<int>> &grid, int k) {
    // Your implementation here

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, false));
    vector<int> dcol = {0, 1, 0, -1};
    vector<int> drow = {-1, 0, 1, 0};
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] != 0 && !visited[i][j]) {
          int total = dfs(i, j, grid, drow, dcol, m, n, visited);
          if (total % k == 0)
            count++;
        }
      }
    }
    return count;
  }
};

int main() {
  Solution sol;

  vector<vector<int>> grid = {{0, 2, 1, 0, 0},
                              {0, 5, 0, 0, 5},
                              {0, 0, 1, 0, 0},
                              {0, 1, 4, 7, 0},
                              {0, 2, 0, 0, 8}};

  int k = 5;

  int result = sol.countIslands(grid, k);
  cout << "Number of islands: " << result << endl;

  return 0;
}
