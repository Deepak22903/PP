#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

class Solution {
public:
  int f(int ind, int amount, vector<int> &coins,
        vector<vector<vector<int>>> &dp, vector<int> &picked) {
    if (amount == 0)
      return 0;
    if (ind < 0)
      return 1e9;

    if (dp[ind][amount][picked[ind]] != -1)
      return dp[ind][amount][picked[ind]];

    // not pick
    int notpick = f(ind - 1, amount, coins, dp, picked);

    // pick
    int pick = 1e9;
    if (coins[ind] <= amount && picked[ind] < 2) {
      picked[ind]++;
      pick = 1 + f(ind, amount - coins[ind], coins, dp, picked);
      picked[ind]--;
    }

    return dp[ind][amount][picked[ind]] = min(pick, notpick);
  }

  int coinChange(vector<int> &coins, int amount) {
    vector<vector<vector<int>>> dp(
        coins.size(), vector<vector<int>>(amount + 1, vector<int>(3, -1)));
    vector<int> picked(coins.size(), 0);
    int res = f(coins.size() - 1, amount, coins, dp, picked);
    return res >= 1e9 ? -1 : res;
  }
};

#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  Solution sol;

  vector<tuple<vector<int>, int, int>> testCases = {
      {{1, 2, 5}, 11, 3},  // 5+5+1 (OK)
      {{1, 2, 5}, 12, -1}, // Cannot use 5 thrice
      {{2}, 4, 2},         // 2+2
      {{1}, 3, -1},        // Only two 1's allowed
      {{1}, 2, 2},         // OK
      {{3, 5}, 11, -1},    // 5+5+1 not allowed (no 1), only 2 uses
      {{2, 3, 5}, 10, 2},  // 5+5 (OK)
      {{2, 3, 5}, 11, -1}, // Needs 3+3+5, but 3 used more than twice
      {{1, 2, 3}, 6, 2},   // 3+3 (OK)
      {{1, 2, 3}, 7, 3},   // 3+3+1 (OK)
  };

  int testCaseNum = 1;
  for (const auto &[coins, amount, expected] : testCases) {
    int result = sol.coinChange(const_cast<vector<int> &>(coins), amount);
    cout << "Test Case " << testCaseNum++ << ": Amount = " << amount
         << ", Coins = [";
    for (int i = 0; i < coins.size(); ++i) {
      cout << coins[i];
      if (i != coins.size() - 1)
        cout << ", ";
    }
    cout << "] => Result: " << result << " | Expected: " << expected << " | "
         << (result == expected ? "✅ Pass" : "❌ Fail") << endl;
  }

  return 0;
}
