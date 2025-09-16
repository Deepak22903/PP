#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> rmDup(vector<int> &arr) {
    unordered_set<int> seen;
    vector<int> result;
    for (int x : arr) {
      if (!seen.count(x)) {
        seen.insert(x);
        result.push_back(x);
      }
    }
    return result;
  }

  int longestConsecutive(vector<int> &nums) {
    if (nums.empty() || nums.size() == 1)
      return nums.size();
    sort(nums.begin(), nums.end());
    nums = rmDup(nums);
    int maxi = 0;
    int i = 0;
    int j = 0;
    while (i < nums.size()) {
      while (i < nums.size() - 1 && nums[i + 1] - nums[i] == 1) {
        i++;
      }
      maxi = max(maxi, i - j + 1);
      i++;
      j = i;
    }
    return maxi;
  }
};

int main() {
  Solution sol;

  // vector<int> nums1 = {100, 4, 200, 1, 3, 2};
  // cout << "Test 1: " << sol.longestConsecutive(nums1) << "\n";
  // // Expected: 4 (sequence: 1, 2, 3, 4)
  //
  // vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  // cout << "Test 2: " << sol.longestConsecutive(nums2) << "\n";
  // // Expected: 9 (sequence: 0,1,2,3,4,5,6,7,8)
  //
  // vector<int> nums3 = {};
  // cout << "Test 3: " << sol.longestConsecutive(nums3) << "\n";
  // // Expected: 0
  //
  // vector<int> nums4 = {9};
  // cout << "Test 4: " << sol.longestConsecutive(nums4) << "\n";
  // // Expected: 1
  vector<int> nums5 = {1, 0, 1, 2};
  cout << "Test 5: " << sol.longestConsecutive(nums5) << "\n";

  return 0;
}
