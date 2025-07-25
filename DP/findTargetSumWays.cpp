#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int f(vector<int> &nums, int target, int i, int sum) {
    if (i < 0) {
      if (sum == target)
        return 1;
      else
        return 0;
    }
    int plus = f(nums, target, i - 1, sum + nums[i]);
    int minus = f(nums, target, i - 1, sum - nums[i]);

    return plus + minus;
  }
  int findTargetSumWays(vector<int> &nums, int target) {
    // implementation goes here
    return f(nums, target, nums.size() - 1, 0);
  }
};

int main() {
  Solution sol;

  vector<pair<vector<int>, int>> testCases = {
      {{1, 1, 1, 1, 1}, 3},  // Expected: 5
      {{1}, 1},              // Expected: 1
      {{1}, 2},              // Expected: 0
      {{2, 3, 5, 6, 8}, 10}, // Expected: varies
      {{0, 0, 0, 0, 0}, 0}   // Expected: 32 (2^5 ways)
  };

  for (int i = 0; i < testCases.size(); i++) {
    vector<int> nums = testCases[i].first;
    int target = testCases[i].second;
    cout << "Test case " << i + 1 << ": " << sol.findTargetSumWays(nums, target)
         << endl;
  }

  return 0;
}
