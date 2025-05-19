#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    // Solution goes here
    for (int i = nums.size() - 1; i > 0; i--) {
      if (nums[i - 1] > nums[i] || nums[i - 1] == nums[i]) {
        continue;
      } else if (nums[i - 1] < nums[i]) {
        sort(nums.begin() + i, nums.end());
        int j = i;
        while (j < nums.size()) {
          if (nums[j] > nums[i - 1])
            break;
          else
            j++;
        }
        swap(nums[i - 1], nums[j]);
        sort(nums.begin() + i, nums.end());
        return;
      }
    }
    sort(nums.begin(), nums.end());
  }
};

int main() {
  vector<int> nums = {3, 2, 1};

  Solution sol;
  sol.nextPermutation(nums);

  // Output the result
  for (int num : nums) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
