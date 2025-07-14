#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int f(int n, vector<vector<int>> &points, int prev, vector<vector<int>> &dp) {
  if (n < 0) {
    return 0;
  }
  if (dp[n][prev] != -1)
    return dp[n][prev];
  int maxP = INT_MIN;
  for (int i = 0; i < 3; i++) {
    if (i != prev) {
      int point = points[n][i] + f(n - 1, points, i, dp);
      maxP = max(maxP, point);
    }
  }
  return dp[n][prev] = maxP;
}

int ninjaTraining(int n, vector<vector<int>> &points) {
  vector<vector<int>> dp(n, vector<int>(4, -1));
  return f(n - 1, points, 3, dp);
}

int main() {
  int n = 3;
  vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};

  int result = ninjaTraining(n, points);
  cout << result << endl;

  return 0;
}
