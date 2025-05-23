#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    vector<int> res;
    unordered_map<int, int> map;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      auto it = map.find(nums[i]);
      if (it != map.end())
        res.push_back(nums[i]);
      else
        map[nums[i]] = i;
    }
    vector<bool> bitmap(n + 1);
    for (int i = 0; i < nums.size(); i++) {
      bitmap[nums[i]] = 1;
    }
    for (int i = 1; i < bitmap.size(); i++) {
      if (bitmap[i] == 0)
        res.push_back(i);
    }

    return res;
  }
  // vector<int> findMissingRepeatingNumbers(vector<int> nums) {
  //   // Solution goes here
  //   vector<int> res;
  //   int slow = 0;
  //   int fast = 0;
  //   while (1) {
  //     slow = nums[slow] - 1;
  //     fast = nums[nums[fast]] - 1;
  //     if (slow == fast)
  //       break;
  //   }
  //   fast = nums[0];
  //   while (slow != fast) {
  //     slow = nums[slow] - 1;
  //     fast = nums[fast] - 1;
  //   }
  //   res.push_back(slow);
  //   vector<bool> bitmap(nums.size() + 1);
  //   for (int i = 0; i < nums.size(); i++) {
  //     bitmap[i] = 1;
  //   }
  //   for (int i = 1; i < bitmap.size(); i++) {
  //     if (bitmap[i] == 0)
  //       res.push_back(i);
  //   }
  //   return res;
  // }
};

int main() {
  vector<int> nums = {3, 1, 2, 5,
                      3}; // Example input: 3 is repeating, 4 is missing

  Solution sol;
  vector<int> result = sol.findMissingRepeatingNumbers(nums);

  // Output the result: [repeating, missing]
  if (result.size() == 2) {
    cout << "Repeating number: " << result[0] << endl;
    cout << "Missing number: " << result[1] << endl;
  } else {
    cout << "Invalid result size." << endl;
  }

  return 0;
}
