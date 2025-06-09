#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    // Implementation goes here
    int l = 0;
    int r = 0;
    int sum = 0;
    int minLen = INT_MAX;
    while (r < nums.size()) {
      if (sum < target) {
        sum += nums[r];
        r++;
      } else {
        minLen = min(minLen, r - l + 1);
        sum -= nums[l];
        l++;
      }
    }
    return minLen;
  }
};

int main() {
  Solution sol;
  int target = 7;
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int result = sol.minSubArrayLen(target, nums);
  cout << "Minimum subarray length: " << result << endl;
  return 0;
}
