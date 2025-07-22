#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  bool tabu(vector<int> &nums, int target, vector<vector<bool>> &dp) {
    for (int i = 0; i < nums.size(); i++) {
      dp[i][0] = true;
    }
    if (nums[0] <= target)
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
  int minimumDifference(vector<int> &nums) {
    int sum = 0;
    for (auto val : nums) {
      sum += val;
    }
    vector<vector<bool>> dp(nums.size(), vector<bool>(sum / 2 + 1, false));
    tabu(nums, sum / 2, dp);
    int mini = 1e9;
    for (int i = 0; i <= sum / 2; i++) {
      if (dp[nums.size() - 1][i] == true) {
        int sub1 = i;
        int sub2 = sum - i;
        mini = min(mini, abs(sub1 - sub2));
      }
    }
    // implementation goes here
    return mini;
  }
};

int main() {
  Solution sol;

  vector<vector<int>> testCases = {
      {1, 2, 3, 9},       // Expected: 3 (split into [1,2,3] and [9])
      {1, 2, 7, 1, 5},    // Expected: 0 (split into [1,2,5] and [7,1])
      {1, 6, 11, 5},      // Expected: 1 (split into [1,6,5] and [11])
      {3, 1, 4, 2, 2},    // Expected: 0 (split into [3,2,2] and [4,1])
      {10, 20, 15, 5, 25} // Expected: 5 (split into [10,20,5] and [15,25])
  };

  for (int i = 0; i < testCases.size(); i++) {
    vector<int> nums = testCases[i];
    cout << "Test case " << i + 1 << ": " << sol.minimumDifference(nums)
         << endl;
  }

  return 0;
}
