#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> res;
  void comb(vector<int> &candidates, int target, int sum, int i,
            vector<int> ds) {
    if (i >= candidates.size()) {
      return;
    }
    if (sum == target) {
      res.push_back(ds);
      return;
    }

    sum += candidates[i];
    ds.push_back(candidates[i]);
    comb(candidates, target, sum, i + 1, ds);
    sum -= candidates[i];
    ds.pop_back();
    comb(candidates, target, sum, i + 1, ds);
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    // Implementation goes here
    comb(candidates, target, 0, 0, {});
    return res;
  }
};

int main() {
  Solution sol;
  vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;
  vector<vector<int>> result = sol.combinationSum2(candidates, target);

  cout << "Combinations that sum to " << target << ":\n";
  for (const auto &combo : result) {
    cout << "[ ";
    for (int num : combo) {
      cout << num << " ";
    }
    cout << "]\n";
  }

  return 0;
}
