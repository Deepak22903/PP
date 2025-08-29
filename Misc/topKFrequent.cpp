#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    priority_queue<pair<int, int>> maxh;
    unordered_map<int, int> mp;
    for (auto val : nums)
      mp[val]++;
    for (auto it : mp) {
      maxh.push({it.second, it.first});
    }
    vector<int> res;
    for (int i = 0; i < k; i++) {
      res.push_back(maxh.top().second);
      maxh.pop();
    }
    return res;

    // Implementation to be added
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1};
  int k = 1;

  vector<int> result = sol.topKFrequent(nums, k);

  // print result
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
