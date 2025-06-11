#include <climits>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int res{};
  void subs(vector<int> &nums, int i, int n, vector<int> sub, int target,
            int mine, int maxe) {
    if (i == n) {
      if (mine != INT_MAX && maxe != INT_MIN && mine + maxe <= target) {
        cout << mine << " " << maxe << endl;
        res++;
      }
      return;
    }
    sub.push_back(nums[i]);
    int tempMin = mine;
    int tempMax = maxe;
    mine = min(mine, nums[i]);
    maxe = max(maxe, nums[i]);
    subs(nums, i + 1, n, sub, target, mine, maxe);
    sub.pop_back();
    mine = tempMin;
    maxe = tempMax;
    subs(nums, i + 1, n, sub, target, mine, maxe);
  }

  int numSubseq(vector<int> &nums, int target) {
    subs(nums, 0, nums.size() - 1, {}, target, INT_MAX, INT_MIN);
    return res;
  }
};

int main() {
  Solution sol;
  vector<int> arr = {3, 5, 6, 7};
  int target = 9;
  cout << sol.numSubseq(arr, target);
}
