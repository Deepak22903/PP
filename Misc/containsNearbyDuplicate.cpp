#include <cstddef>
#include <iostream>
#include <map>
#include <type_traits>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    map<int, int> dupMap;
    int i = 0;
    while (i < nums.size() && i <= k) {
      if (dupMap.find(nums[i]) != dupMap.end()) {
        return true;
      } else {
        dupMap[nums[i]] = i;
      }
      i++;
    }
    int j = 1;
    while (i < nums.size()) {
      dupMap.erase(nums[j - 1]);
      if (dupMap.find(nums[i]) != dupMap.end()) {
        return true;
      } else {
        dupMap[nums[i]] = i;
      }
      i++;
      j++;
    }
    return false;
  }

  // Time limit
  // bool containsNearbyDuplicate(vector<int> &nums, int k) {
  //   // Implementation goes here
  //   int l{};
  //   int r = 1;
  //   while (l < nums.size()) {
  //     while (r < nums.size() && nums[r] != nums[l]) {
  //       r++;
  //     }
  //     if ((r - l) <= k && r < nums.size()) {
  //       return true;
  //     } else {
  //       l++;
  //       r = l + 1;
  //     }
  //   }
  //   return false;
  // }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 1};
  int k = 3;
  bool result = sol.containsNearbyDuplicate(nums, k);
  cout << (result ? "True" : "False") << endl;
  return 0;
}
