#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    set<vector<int>> seen;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      unordered_map<int, int> map;
      int target = -nums[i];
      for (int j = i + 1; j < nums.size(); j++) {
        int num = target - nums[j];
        auto it = map.find(num);
        if (it != map.end()) {
          if (it->second != j) {

            vector<int> arr = {nums[i], nums[j], nums[it->second]};
            sort(arr.begin(), arr.end());
            if (seen.find(arr) == seen.end()) {
              res.push_back(arr);
              seen.insert(arr);
            }
          }
        }
        map[nums[j]] = j;
      }
    }
    return res;
  }
};

int main() {}
