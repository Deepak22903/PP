#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      auto it = map.find(nums[i]);
      if (it == map.end()) {
        map[nums[i]] = i;
      } else {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {1};
  cout << sol.containsDuplicate(arr) << endl;
}
