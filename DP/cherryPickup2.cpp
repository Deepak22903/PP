#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

class Solution {
private:
  int f(int i, int j1, int j2, vector<vector<int>> &grid, int n, int m,
        vector<vector<vector<int>>> &dp) {
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
      return -1e8;
    if (i == n - 1) {
      if (j1 == j2)
        return grid[i][j1];
      else
        return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1)
      return dp[i][j1][j2];

    vector<int> dc = {-1, 0, 1};
    int maxi = INT_MIN;
    for (int dj1 = 0; dj1 < dc.size(); dj1++) {
      for (int dj2 = 0; dj2 < dc.size(); dj2++) {
        int cherry = 0;
        if (j1 == j2)
          cherry = grid[i][j1] +
                   f(i + 1, j1 + dc[dj1], j2 + dc[dj2], grid, n, m, dp);
        else
          cherry = grid[i][j1] + grid[i][j2] +
                   f(i + 1, j1 + dc[dj1], j2 + dc[dj2], grid, n, m, dp);
        maxi = max(maxi, cherry);
      }
    }
    return dp[i][j1][j2] = maxi;
  }

public:
  int cherryPickup(vector<vector<int>> &grid) {

    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(m, vector<int>(m, -1)));
    // Implementation goes here
    return f(0, 0, m - 1, grid, n, m, dp);
  }
};

int main() {
  Solution sol;

  vector<vector<vector<int>>> testCases = {
      {// Test 1
       {3, 1, 1},
       {2, 5, 1},
       {1, 5, 5},
       {2, 1, 1}},
      {// Test 2: Single row
       {1, 2, 3}},
      {// Test 3: All zero grid
       {0, 0, 0},
       {0, 0, 0}},
      {// Test 4: Large cherries in the middle
       {1, 0, 0, 0, 1},
       {2, 0, 0, 0, 2},
       {3, 0, 100, 0, 3},
       {4, 0, 0, 0, 4}},
      {// Test 5: Narrow grid
       {1},
       {2},
       {3}}};

  for (int i = 0; i < testCases.size(); i++) {
    vector<vector<int>> grid = testCases[i];
    cout << "Test case " << i + 1 << ": ";
    cout << sol.cherryPickup(grid) << endl;
  }

  return 0;
}
