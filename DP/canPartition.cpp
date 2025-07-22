#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
private:
  bool tabu(vector<int> &nums, int i, int target, vector<vector<int>> &dp) {
    for (int i = 0; i < nums.size(); i++) {
      dp[i][0] = true;
    }
    dp[0][nums[0]] = true;
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 1; j <= target; j++) {
        bool notpick = dp[i - 1][j];
        bool pick = false;
        if (nums[i] <= j) {
          pick = dp[i - 1][j - nums[i]];
        }
        dp[i][j] = pick | notpick;
      }
    }
    return dp[nums.size() - 1][target];
  }
  bool f(vector<int> &nums, int i, int target, vector<vector<int>> &dp) {
    if (target == 0)
      return true;
    if (i == 0)
      return target == nums[0];
    if (dp[i][target] != -1)
      return dp[i][target];
    bool notpick = f(nums, i - 1, target, dp);
    bool pick = false;
    if (nums[i] <= target) {
      pick = f(nums, i - 1, target - nums[i], dp);
    }
    return dp[i][target] = pick | notpick;
  }

public:
  bool canPartition(vector<int> &nums) {
    // implementation goes here
    int n = nums.size();
    int sum = 0;
    for (int val : nums) {
      sum += val;
    }
    if (sum % 2 != 0)
      return false;
    int target = sum / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    return tabu(nums, n - 1, target, dp);
  }
};

int main() {
  Solution sol;

  vector<vector<int>> testCases = {
      {1, 5, 11, 5}, // Expected: true (subset [1,5,5] and [11])
      {1, 2, 3, 5},  // Expected: false
      {2, 2, 3, 5},  // Expected: false
      {1, 1},        // Expected: true
      {2, 2, 2, 2}   // Expected: true
  };

  for (int i = 0; i < testCases.size(); i++) {
    vector<int> nums = testCases[i];
    cout << "Test case " << i + 1 << ": "
         << (sol.canPartition(nums) ? "true" : "false") << endl;
  }

  return 0;
}
