#include <bits/stdc++.h>
#include <climits>
#include <filesystem>
#include <vector>
using namespace std;

class Solution {
private:
  int tabu(vector<int> &coins, int amount, int i, vector<vector<int>> &dp) {
    for (int i = 0; i <= amount; i++) {
      if (i % coins[0] == 0)
        dp[0][i] = i / coins[0];
      else
        dp[0][i] = 1e9;
    }
    for (int i = 1; i < coins.size(); i++) {
      for (int j = 0; j <= amount; j++) {
        int notpick = dp[i - 1][j];
        int pick = INT_MAX;
        if (coins[i] <= j)
          pick = 1 + dp[i][j - coins[i]];
        dp[i][j] = min(pick, notpick);
      }
    }
    return dp[coins.size() - 1][amount];
  }

public:
  int coinChange(vector<int> &coins, int amount) {
    // implementation goes here
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    int res = tabu(coins, amount, coins.size() - 1, dp);
    if (res >= 1e9)
      return -1;
    else
      return res;
    //
  }
};

int f(vector<int> &coins, int amount, int i, vector<vector<int>> &dp) {
  if (i == 0) {
    if (amount % coins[0] == 0)
      return amount / coins[0];
    else
      return 1e9;
  }
  if (dp[i][amount] != -1)
    return dp[i][amount];
  int notpick = f(coins, amount, i - 1, dp);
  int pick = INT_MAX;
  if (coins[i] <= amount)
    pick = 1 + f(coins, amount - coins[i], i, dp);
  return dp[i][amount] = min(pick, notpick);
}
int main() {
  Solution sol;

  vector<pair<vector<int>, int>> testCases = {
      {{1, 2, 5}, 11},            // Expected: 3 (5+5+1)
      {{2}, 3},                   // Expected: -1 (not possible)
      {{1}, 0},                   // Expected: 0 (no coins needed)
      {{1}, 2},                   // Expected: 2 (1+1)
      {{186, 419, 83, 408}, 6249} // Large test case
  };

  for (int i = 0; i < testCases.size(); i++) {
    vector<int> coins = testCases[i].first;
    int amount = testCases[i].second;
    cout << "Test case " << i + 1 << ": " << sol.coinChange(coins, amount)
         << endl;
  }

  return 0;
}
