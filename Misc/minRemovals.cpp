#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minRemoval(vector<int> &nums, int k) {
    if (nums.size() == 1)
      return 0;
    sort(nums.begin(), nums.end());
    int res = 0;
    for (int left = 0; left < nums.size(); left++) {
      int right = nums.size() - 1;
      while (nums[right] > (long long)nums[left] * k)
        right--;
      res = max(res, right - left + 1);
    }
    // Implementation goes here
    return nums.size() - res;
  }
};

int main() {
  Solution sol;

  vector<int> nums1 = {2, 1, 5};
  int k1 = 2;
  cout << "Test Case 1: " << sol.minRemoval(nums1, k1) << endl;

  vector<int> nums2 = {1, 6, 2, 9};
  int k2 = 3;
  cout << "Test Case 2: " << sol.minRemoval(nums2, k2) << endl;

  vector<int> nums3 = {4, 6};
  int k3 = 2;
  cout << "Test Case 3: " << sol.minRemoval(nums3, k3) << endl;

  return 0;
}
