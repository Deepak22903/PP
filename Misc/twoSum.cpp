
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      auto it = map.find(target - nums[i]);
      if (it == map.end()) {
        map[nums[i]] = i;
        continue;
      }

      return {i, it->second};
    }
    return {};
  }
};

int main() {
  vector<int> nums = {3, 2, 4}; // Example input
  int target = 6;

  Solution sol;
  vector<int> result = sol.twoSum(nums, target);

  // Output the result
  if (result.size() == 2) {
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
  } else {
    cout << "No valid pair found." << endl;
  }

  return 0;
}
