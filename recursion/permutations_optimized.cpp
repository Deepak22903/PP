#include <iostream>
#include <vector>
using namespace std;

void permute(vector<int> &nums, int index, vector<vector<int>> &res) {
  if (index == nums.size()) {
    res.push_back(nums);
    return;
  }
  for (int i = index; i < nums.size(); i++) {
    swap(nums[index], nums[i]);
    permute(nums, index + 1, res);
    swap(nums[index], nums[i]);
  }
}

int main(int argc, char *argv[]) {
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> res;
  permute(nums, 0, res);
  for (auto it : res) {
    for (auto val : it) {
      cout << val << " ";
    }
    cout << endl;
  }
  return 0;
}
