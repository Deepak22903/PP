#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int f(int amount, vector<int> &coins, int ind, vector<vector<int>> &dp) {
    if (ind == 0) {
      return (amount % coins[0] == 0);
    }

    if (dp[ind][amount] != -1)
      return dp[ind][amount];

    int notpick = f(amount, coins, ind - 1, dp);
    int pick = 0;
    if (coins[ind] <= amount)
      pick = f(amount - coins[ind], coins, ind, dp);

    return dp[ind][amount] = notpick + pick;
  }
  int change(int amount, vector<int> &coins) {
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    // implementation goes here
    return f(amount, coins, coins.size() - 1, dp);
  }
};

int main() {
  Solution sol;

  vector<pair<int, vector<int>>> testCases = {
      {5, {1, 2, 5}}, // Expected: 4
      {3, {2}},       // Expected: 0
      {10, {10}},     // Expected: 1
      {0, {1, 2, 5}}, // Expected: 1
      {7, {1, 2, 3}}, // Expected: 8
  };

  for (int i = 0; i < testCases.size(); i++) {
    int amount = testCases[i].first;
    vector<int> coins = testCases[i].second;
    cout << "Test case " << i + 1 << ": " << sol.change(amount, coins) << endl;
  }

  return 0;
}
