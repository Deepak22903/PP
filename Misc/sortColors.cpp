#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    int r = 0;
    int w = 0;
    int b = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0) {
        r++;
      } else if (nums[i] == 1) {
        w++;
      } else {
        b++;
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (r) {
        nums[i] = 0;
        r--;
      } else if (w) {
        nums[i] = 1;
        w--;
      } else {
        nums[i] = 2;
        b--;
      }
    }
  }
  // void sortColors(vector<int> &nums) {
  //   // Solution goes here
  //   for (int j = 0; j < nums.size(); j++) {
  //
  //     for (int i = 0; i < nums.size(); i++) {
  //       if (nums[i] == 0) {
  //         nums.erase(nums.begin() + i);
  //         nums.insert(nums.begin(), 0);
  //       } else if (nums[i] == 2) {
  //         nums.erase(nums.begin() + i);
  //         nums.push_back(2);
  //       }
  //     }
  //   }
  // }
};

int main() {
  vector<int> nums = {2, 0, 2, 1, 1, 0};

  Solution sol;
  sol.sortColors(nums);

  // Output the result
  for (int num : nums) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
