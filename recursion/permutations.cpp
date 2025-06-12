#include <iostream>
#include <vector>

using namespace std;

void permute(vector<int> &nums, int index, vector<bool> &picked,
             vector<vector<int>> &res, vector<int> ds) {
  if (index >= nums.size()) {
    res.push_back(ds);
    return;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (picked[i] == true)
      continue;
    picked[i] = true;
    ds.push_back(nums[i]);
    permute(nums, index + 1, picked, res, ds);
    picked[i] = false;
    ds.pop_back();
  }
}

int main() {
  vector<int> arr = {1, 2, 3};
  vector<bool> picked(arr.size());
  vector<vector<int>> res;
  permute(arr, 0, picked, res, {});
  for (auto it : res) {
    for (auto val : it) {
      cout << val << " ";
    }
    cout << endl;
  }
}
