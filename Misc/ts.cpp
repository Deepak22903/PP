#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> map;
  for (int i = 0; i < nums.size(); i++) {
    int complement = target - nums[i];
    if (map.find(complement) != map.end()) {
      return {map[complement], i};
    }
    map[nums[i]] = i;
  }
  return {};
}

int main() {
  vector<int> input = {1, 2, 3, 4, 5, 6};
  int t = 5;
  vector<int> res = twoSum(input, t);
  for (int i : res) {
    cout << i << " ";
  }
  return 0;
}
