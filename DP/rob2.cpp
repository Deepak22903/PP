#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {

public:
  int f(vector<int> &nums, int ind, vector<int> &dp) {
    if (ind < 0)
      return 0;

    if (dp[ind] != -1)
      return dp[ind];
    int notpick = f(nums, ind - 1, dp);
    int pick = nums[ind] + f(nums, ind - 2, dp);
    return dp[ind] = max(notpick, pick);
  }
  int rob(vector<int> &nums) {
    if (nums.size() == 1)
      return nums[0];
    vector<int> dp1(nums.size(), -1);
    int a = f(nums, nums.size() - 2, dp1);
    vector<int> arr(nums.begin() + 1, nums.end());
    vector<int> dp2(arr.size(), -1);
    int b = f(arr, arr.size() - 1, dp2);

    return a > b ? a : b;
  }
};

int main() {
  vector<int> nums = {2, 7, 9, 3, 1}; // example input
  Solution sol;
  cout << sol.rob(nums) << endl;
  return 0;
}
