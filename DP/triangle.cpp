#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int tabu(vector<vector<int>> &triangle, int r, int c, vector<vector<int>> &dp,
           int n) {
    for (int c = 0; c < n; c++) {
      dp[n - 1][c] = triangle[n - 1][c];
    }

    for (int r = n - 2; r >= 0; r--) {
      for (int c = r; c >= 0; c--) {
        int down = triangle[r][c] + dp[r + 1][c];
        int right = triangle[r][c] + dp[r + 1][c + 1];
        dp[r][c] = min(down, right);
      }
    }
    return dp[0][0];
  }
  int f(vector<vector<int>> &triangle, int r, int c, vector<vector<int>> &dp,
        int n) {
    if (r == n - 1) {
      return triangle[r][c];
    }

    if (dp[r][c] != -1)
      return dp[r][c];
    int down = triangle[r][c] + f(triangle, r + 1, c, dp, n);
    int right = triangle[r][c] + f(triangle, r + 1, c + 1, dp, n);
    return dp[r][c] = min(down, right);
  }
  int minimumTotal(vector<vector<int>> &triangle) {
    // implementation goes here
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return tabu(triangle, 0, 0, dp, n);
  }
};

int main() {
  Solution sol;

  vector<vector<vector<int>>> testCases = {
      {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}}, // expected: 11
      {{-10}},                                // expected: -10
      {{1}, {2, 3}},                          // expected: 3
      {{1}, {2, 3}, {4, 5, 6}},               // expected: 7
      {{1}, {1, 2}, {1, 2, 3}, {1, 2, 3, 4}}  // expected: 4
  };

  for (size_t i = 0; i < testCases.size(); i++) {
    vector<vector<int>> triangle = testCases[i];
    int result = sol.minimumTotal(triangle);
    cout << "Test case " << i + 1 << " -> Minimum Path Sum: " << result << endl;
  }

  return 0;
}
