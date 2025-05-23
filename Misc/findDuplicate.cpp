#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    // Solution goes here
    int slow = 0;
    int fast = 0;
    while (1) {
      slow = nums[slow];
      fast = nums[nums[fast]];
      if (slow == fast)
        break;
    }
    fast = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};

int main() {
  vector<int> nums = {1, 3, 4, 2, 2};

  Solution sol;
  int duplicate = sol.findDuplicate(nums);

  // Output the duplicate number
  cout << "Duplicate number: " << duplicate << endl;

  return 0;
}
