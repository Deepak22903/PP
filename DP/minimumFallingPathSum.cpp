#include <climits>
#include <iostream>
#include <vector>

// Using the standard namespace as requested
using namespace std;

// The Solution class with the method for you to implement.
class Solution {
public:
  int tabu(vector<vector<int>> &matrix, int n, vector<vector<int>> &dp) {
    for (int c = 0; c < n; c++) {
      dp[n - 1][c] = matrix[n - 1][c];
    }
    for (int r = n - 2; r >= 0; r--) {
      for (int c = n - 1; c >= 0; c--) {
        int down = matrix[r][c], diaLeft = matrix[r][c],
            diaRight = matrix[r][c];
        down += dp[r + 1][c];
        if (c > 0)
          diaLeft += dp[r + 1][c - 1];
        else
          diaLeft += 1e9;
        if (c < n - 1)
          diaRight += dp[r + 1][c + 1];
        else
          diaRight += 1e9;
        dp[r][c] = min(down, min(diaLeft, diaRight));
      }
    }
    return dp[0][0];
  }
  int memo(vector<vector<int>> &matrix, int n, int r, int c,
           vector<vector<int>> &dp) {
    if (r < 0 || r > n - 1 || c < 0 || c > n - 1)
      return 1e9;
    if (r == n - 1)
      return matrix[r][c];
    if (dp[r][c] != -1)
      return dp[r][c];

    int down = matrix[r][c] + f(matrix, n, r + 1, c);
    int diaLeft = matrix[r][c] + f(matrix, n, r + 1, c - 1);
    int diaRight = matrix[r][c] + f(matrix, n, r + 1, c + 1);

    return dp[r][c] = min(down, min(diaLeft, diaRight));
  }
  int f(vector<vector<int>> &matrix, int n, int r, int c) {
    if (r < 0 || r > n - 1 || c < 0 || c > n - 1)
      return 1e9;
    if (r == n - 1)
      return matrix[r][c];

    int down = matrix[r][c] + f(matrix, n, r + 1, c);
    int diaLeft = matrix[r][c] + f(matrix, n, r + 1, c - 1);
    int diaRight = matrix[r][c] + f(matrix, n, r + 1, c + 1);

    return min(down, min(diaLeft, diaRight));
  }
  int minFallingPathSum(vector<vector<int>> &matrix) {

    // --- YOUR CODE GOES HERE ---

    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int minS = INT_MAX;
    tabu(matrix, n, dp);
    for (int i = 0; i < n; i++) {
      minS = min(minS, dp[0][i]);
    }
    // Placeholder return to allow compilation while you work.
    return minS;
  }
};

// Helper function to run a test and print the result
void runTest(const string &testName, vector<vector<int>> matrix, int expected) {
  cout << "--- " << testName << " ---" << endl;

  vector<vector<int>> matrixForDisplay = matrix;
  cout << "Input Matrix:" << endl;
  for (const auto &row : matrixForDisplay) {
    for (int val : row) {
      cout << val << "\t";
    }
    cout << endl;
  }

  Solution sol;
  int result = sol.minFallingPathSum(matrix);

  cout << "\nResult from your function: " << result << endl;
  cout << "Expected result:         " << expected << endl;
  cout << "----------------------------------" << endl << endl;
}

int main() {
  // Test Case 1: Standard 3x3 Case
  vector<vector<int>> matrix1 = {{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
  runTest("Standard 3x3 Case", matrix1, 13);

  // Test Case 2: 2x2 with Negative Numbers
  vector<vector<int>> matrix2 = {{-19, 57}, {-40, -5}};
  runTest("2x2 with Negative Numbers", matrix2, -59);

  // Test Case 3: 1x1 Matrix (Edge Case)
  vector<vector<int>> matrix3 = {{-100}};
  runTest("1x1 Matrix", matrix3, -100);

  // Test Case 4: 4x4 Complex Path
  // The optimal path here is 1 -> 1 -> 1 -> 10 = 13
  vector<vector<int>> matrix4 = {
      {10, 10, 1, 10}, {10, 1, 10, 10}, {1, 10, 10, 10}, {10, 10, 10, 1}};
  runTest("4x4 Complex Path", matrix4, 13);

  // Test Case 5: 3x3 with All Same Values
  vector<vector<int>> matrix5 = {{5, 5, 5}, {5, 5, 5}, {5, 5, 5}};
  runTest("3x3 All Same Values", matrix5, 15);

  return 0;
}
