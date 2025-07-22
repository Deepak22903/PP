
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {

public:
  int subarraySum(vector<int> &nums, int k) {
    int res = 0;

    return res;
  }
};

int main() {
  Solution sol;

  vector<pair<vector<int>, int>> testCases = {
      {{1, 1, 1}, 2},                 // Expected: 2
      {{1, 2, 3}, 3},                 // Expected: 2 ([1,2], [3])
      {{1, -1, 0}, 0},                // Expected: 3 ([1,-1], [0], [1,-1,0])
      {{3, 4, 7, 2, -3, 1, 4, 2}, 7}, // Expected: 4
      {{1}, 0}                        // Expected: 0
  };

  for (int i = 0; i < testCases.size(); i++) {
    vector<int> nums = testCases[i].first;
    int k = testCases[i].second;
    cout << "Test case " << i + 1 << ": " << sol.subarraySum(nums, k) << endl;
  }

  return 0;
}
