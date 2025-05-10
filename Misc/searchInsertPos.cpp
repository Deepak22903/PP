#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    // implementation to be filled
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j) {
      int mid = i + (j - i) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        i = mid + 1;
      } else {
        j = mid - 1;
      }
    }
    return i;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 3, 5, 6};
  int target = 0;

  int index = sol.searchInsert(nums, target);
  cout << "Target should be at index: " << index << endl;

  return 0;
}
