
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int f(int n, int m, vector<vector<int>> &grid, int i, int j) {
    if (i == n)
      return 0;
    int left = 0, right = 0;
    if (j > 0)
      left = grid[i][j] + f(n, m, grid, i + 1, j - 1);
    if (j < m - 1)
      right = grid[i][j] + f(n, m, grid, i + 1, j + 1);
    return max(left, right);
  }
  int getMaximumGold(vector<vector<int>> &grid) {
    // Your implementation here
    int n = grid.size();
    int m = grid[0].size();
    int maxi = -1e8;
    for (int j = 0; j < m; j++) {
      maxi = max(maxi, f(n, m, grid, 0, j));
    }
    return maxi;
  }
};

int main() {
  Solution sol;

  vector<vector<int>> grid1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // Expected: 3 → 6 → 8 = 17
  cout << "Test Case 1: " << sol.getMaximumGold(grid1) << " (Expected: 17)"
       << endl;

  vector<vector<int>> grid2 = {
      {10, 33, 13, 15}, {22, 21, 4, 1}, {5, 0, 2, 3}, {0, 6, 14, 2}};
  // Expected path: 33 → 4 → 3 → 14 = 54
  cout << "Test Case 2: " << sol.getMaximumGold(grid2) << " (Expected: 54)"
       << endl;

  vector<vector<int>> grid3 = {{1, 2}, {3, 4}};
  // Expected: 2 → 3 = 5
  cout << "Test Case 3: " << sol.getMaximumGold(grid3) << " (Expected: 5)"
       << endl;

  vector<vector<int>> grid4 = {{100}};
  // Expected: 100 (only one cell)
  cout << "Test Case 4: " << sol.getMaximumGold(grid4) << " (Expected: 100)"
       << endl;

  vector<vector<int>> grid5 = {{1, 2, 3, 4}, {0, 0, 0, 0}, {9, 8, 7, 6}};
  // Expected: 4 → 0 → 7 = 11
  cout << "Test Case 5: " << sol.getMaximumGold(grid5) << " (Expected: 11)"
       << endl;

  return 0;
}
