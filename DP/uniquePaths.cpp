#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int f(int r, int c, vector<vector<int>> &dp) {
    if (r == 0 && c == 0)
      return 1;
    if (r < 0 || c < 0)
      return 0;
    if (dp[r][c] != -1)
      return dp[r][c];
    int top = f(r - 1, c, dp);
    int left = f(r, c - 1, dp);
    return dp[r][c] = top + left;
  }
  int tab(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0] = 1;
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        if (r != 0 && c != 0) {
          int top = 0, left = 0;
          if (c > 0)
            top = dp[r][c - 1];
          if (r > 0)
            left = dp[r - 1][c];
          dp[r][c] = top + left;
        }
      }
    }
    return dp[m - 1][n - 1];
  }

  int spaceOpti(int m, int n) {
    vector<int> temp(n), prev(n, 0);
    temp[0] = 1;
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        if (i > 0) {
          int top = 0, left = 0;
          top = prev[i];
          left = temp[i - 1];
          temp[i] = top + left;
        }
      }
      prev = temp;
    }
    return temp[n - 1];
  }
  int uniquePaths(int m, int n) {
    // Implementation goes here
    vector<vector<int>> dp(m, vector<int>(n, -1));
    // return f(m - 1, n - 1, dp);
    // return tab(m, n);
    return spaceOpti(m, n);
  }
};

int main() {
  Solution sol;
  int m = 10000, n = 10000;
  cout << "Number of unique paths for " << m << "x" << n
       << " grid: " << sol.uniquePaths(m, n) << endl;
  return 0;
}
