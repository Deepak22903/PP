#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int f(int r, int c, vector<vector<int>> &obstacleGrid,
        vector<vector<int>> &dp) {
    if (r >= 0 && c >= 0 && obstacleGrid[r][c] == 1)
      return 0;
    if (r == 0 && c == 0)
      return 1;
    if (r < 0 || c < 0)
      return 0;
    if (dp[r][c] != -1)
      return dp[r][c];
    int top = f(r - 1, c, obstacleGrid, dp);
    int left = f(r, c - 1, obstacleGrid, dp);
    return dp[r][c] = top + left;
  }

  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    // Implementation goes here
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, obstacleGrid, dp);
  }
};

int main() {
  Solution sol;

  vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

  cout << "Unique paths avoiding obstacles: "
       << sol.uniquePathsWithObstacles(obstacleGrid) << endl;

  return 0;
}
