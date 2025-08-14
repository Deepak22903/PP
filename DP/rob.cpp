#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int f(vector<int> &nums, int ind, int prev, vector<vector<int>> &dp) {

    if (ind < 0) {
      return 0;
    }
    if (dp[ind][prev] != -1)
      return dp[ind][prev];

    int notpick = f(nums, ind - 1, prev, dp);
    int pick = 0;
    if (prev != ind + 1)
      pick = nums[ind] + f(nums, ind - 1, ind, dp);
    return dp[ind][prev] = max(notpick, pick);
  }
  int rob(vector<int> &nums) {

    vector<vector<int>> dp(nums.size(), vector<int>(nums.size() + 2, -1));
    return f(nums, :)
    // implementation goes here
  }
};

int main() {
  vector<int> nums = {2, 7, 9, 3, 1}; // example input
  Solution sol;

  cout << sol.rob(nums) << endl;
  return 0;
}
