#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int maxSum = nums[0];
    int currSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      currSum = max(nums[i], currSum + nums[i]);
      maxSum = max(currSum, maxSum);
    }
    return maxSum;
  }
  // int maxSubArray(vector<int> &nums) {
  //   // Solution goes here
  //   int maxSum = INT_MIN;
  //   for (int i = 1; i <= nums.size(); i++) {
  //     int currSum = 0;
  //     for (int j = 0; j < i; j++) {
  //       currSum += nums[j];
  //       maxSum = max(currSum, maxSum);
  //     }
  //     for (int k = i; k < nums.size(); k++) {
  //       currSum = currSum + nums[k] - nums[k - i];
  //       maxSum = max(currSum, maxSum);
  //     }
  //   }
  //   return maxSum;
  // }
};

int main() {
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

  Solution sol;
  int result = sol.maxSubArray(nums);

  // Output the result
  cout << "Maximum subarray sum: " << result << endl;

  return 0;
}
