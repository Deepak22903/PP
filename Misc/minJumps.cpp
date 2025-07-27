#include <bits/stdc++.h>
#include <vector>

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPrime(int n) {
    if (n < 2)
      return false;
    if (n % 2 == 0)
      return n == 2;
    if (n % 3 == 0)
      return n == 3;
    for (int i = 5; 1LL * i * i <= n; i += 6)
      if (n % i == 0 || n % (i + 2) == 0)
        return false;
    return true;
  }

  int f(vector<int> &nums, int ind, vector<int> &dp) {
    if (ind >= nums.size() - 1)
      return 0;
    if (dp[ind] != -1)
      return dp[ind];

    int notpick = 1 + f(nums, ind + 1, dp);
    int pick = 1e9;

    if (isPrime(nums[ind])) {
      int prime = nums[ind];
      int i = ind + 1;
      while (i < nums.size() && nums[i] % prime != 0)
        i++;
      if (i < nums.size())
        pick = 1 + f(nums, i, dp);
    }

    return dp[ind] = min(pick, notpick);
  }

  int minJumps(vector<int> &nums) {
    vector<int> dp(nums.size(), -1);
    return f(nums, 0, dp);
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 4, 6};
  int result = sol.minJumps(nums);
  cout << "Minimum jumps: " << result << endl;
  return 0;
}
