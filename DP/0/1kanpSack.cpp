#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
private:
  int tabu(int i, int W, vector<int> &val, vector<int> &wt,
           vector<vector<int>> &dp) {

    // Base case: first row
    vector<int> prev(W + 1, 0);
    for (int j = 0; j <= W; j++) {
      if (wt[0] <= j)
        prev[j] = val[0];
      else
        prev[j] = 0;
    }
    for (int i = 1; i < val.size(); i++) {
      for (int j = W; j >= 0; j--) {
        int notpick = prev[j];
        int pick = 0;
        if (wt[i] <= j)
          pick = val[i] + prev[j - wt[i]];
        prev[j] = max(notpick, pick);
      }
    }
    return prev[W];
  }
  int f(int i, int W, vector<int> &val, vector<int> &wt,
        vector<vector<int>> &dp) {

    if (i < 0 || W <= 0)
      return 0;
    if (i == 0) {
      if (wt[0] <= W) {
        return val[0];
      } else {
        return 0;
      }
    }
    if (dp[i][W] != -1)
      return dp[i][W];
    int notpick = 0 + f(i - 1, W, val, wt, dp);
    int pick = 0;
    if (wt[i] <= W)
      pick = val[i] + f(i - 1, W - wt[i], val, wt, dp);

    return dp[i][W] = max(pick, notpick);
  }

public:
  int knapsack(int W, vector<int> &val, vector<int> &wt) {

    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    // code here
    return tabu(val.size() - 1, W, val, wt, dp); // placeholder
  }
};

int main() {
  Solution sol;

  vector<int> val1 = {60, 100, 120};
  vector<int> wt1 = {10, 20, 30};
  int W1 = 50; // Expected: 220 (items 2 and 3)

  vector<int> val2 = {1, 2, 3};
  vector<int> wt2 = {4, 5, 1};
  int W2 = 4; // Expected: 3 (item 3 only)

  vector<int> val3 = {10, 40, 30, 50};
  vector<int> wt3 = {5, 4, 6, 3};
  int W3 = 10; // Expected: 90 (items 2 and 4)

  cout << "Test case 1: " << sol.knapsack(W1, val1, wt1) << endl;
  cout << "Test case 2: " << sol.knapsack(W2, val2, wt2) << endl;
  cout << "Test case 3: " << sol.knapsack(W3, val3, wt3) << endl;

  return 0;
}
