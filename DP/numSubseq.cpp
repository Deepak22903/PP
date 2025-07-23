#include <bits/stdc++.h>
using namespace std;

class solution {
private:
  int f(vector<int> &nums, int target, int mini, int maxi, int i, bool taken) {
    if (i < 0) {
      if (taken && (mini + maxi) <= target)
        return 1;
      else
        return 0;
    }

    int currmin = taken ? min(nums[i], mini) : nums[i];
    int currmax = taken ? max(nums[i], maxi) : nums[i];
    int pick = f(nums, target, currmin, currmax, i - 1, true);
    int notpick = f(nums, target, mini, maxi, i - 1, taken);
    return pick + notpick;
  }

public:
  int numsubseq(vector<int> &nums, int target) {
    // implementation goes here
    int n = nums.size();
    return f(nums, target, 1e9, -1e8, n - 1, false);
  }
};

int main() {
  solution sol;

  vector<pair<vector<int>, int>> testcases = {
      {{3, 5, 6, 7}, 9},           // expected: 4
      {{3, 3, 6, 8}, 10},          // expected: 6
      {{2, 3, 3, 4, 6, 7}, 12},    // expected: 61
      {{5, 2, 4, 1, 7, 6, 8}, 16}, // expected: varies
      {{1}, 1},                    // expected: 1
      {{1}, 0},                    // expected: 0
  };

  for (int i = 0; i < testcases.size(); i++) {
    vector<int> nums = testcases[i].first;
    int target = testcases[i].second;
    cout << "test case " << i + 1 << ": " << sol.numsubseq(nums, target)
         << endl;
  }

  return 0;
}
