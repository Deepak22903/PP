#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int missingNumber(vector<int> &nums);
};
// int Solution::missingNumber(vector<int> &nums) {
//   vector<bool> bitmap(nums.size() + 1);
//   for (int i = 0; i < nums.size(); i++) {
//     bitmap[nums[i]] = true;
//   }
//   for (int i = 0; i < bitmap.size(); i++) {
//     if (bitmap[i] == false) {
//       return i;
//     }
//   }
//   return -1;
// }

int Solution::missingNumber(vector<int> &nums) {
  int n = nums.size() + 1;
  long long actualSum = (n * (n - 1)) / 2;
  long long currSum = 0;
  for (int val : nums)
    currSum += val;
  return actualSum - currSum;
}

int main() {
  vector<int> arr = {1, 0, 3};
  Solution sol;
  cout << sol.missingNumber(arr) << endl;
}
