#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  vector<vector<int>> res{};
  vector<int> nums{4, 5, 2, 1, -1, 0, 0, -2, -3};
  // if(nums.size() < 3) return {};
  sort(nums.begin(), nums.end());
  for (int k = 0; nums[k] < 0; k++) {
    if (k > 0 && nums[k] == nums[k - 1]) {
      continue;
    }
    int target = -nums[k];
    int i = k + 1;
    int j = nums.size() - 1;
    while (i < j) {
      if ((nums[i] + nums[j]) > target) {
        j--;
      } else if ((nums[i] + nums[j]) < target) {
        i++;
      } else if ((nums[i] + nums[j]) == target) {
        res.push_back({nums[k], nums[i], nums[j]});
        i++;
        j--;
        while (i < j && nums[i] == nums[i - 1])
          i++;
        while (i < j && nums[j] == nums[j + 1])
          j--;
      }
    }
  }
  for (const auto &row : res) { // Iterate over each inner vector
    for (int num : row) {       // Iterate over each element in the inner vector
      cout << num << " ";
    }
    cout << endl; // New line after each inner vector
  }
  return 0;
}
