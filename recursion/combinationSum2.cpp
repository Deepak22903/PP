#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> res;
  void comb(vector<int> &candidates, int target, int sum, int i,
            vector<int> ds) {
    if (sum == target) {
      res.push_back(ds);
      return;
    }

    for (int k = i; k < candidates.size(); k++) {
      if (k > i && candidates[k] == candidates[k - 1]) {
        continue;
      }
      if (sum > target)
        break;
      sum += candidates[k];
      ds.push_back(candidates[k]);
      comb(candidates, target, sum, k + 1, ds);
      sum -= candidates[k];
      ds.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    // Implementation goes here
    sort(candidates.begin(), candidates.end());
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
