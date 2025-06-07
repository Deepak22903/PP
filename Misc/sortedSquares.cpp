#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n);
    int i = n - 1;

    int l = 0;
    int r = n - 1;
    while (l <= r) {
      int rS = nums[r] * nums[r];
      int lS = nums[l] * nums[l];
      if (rS > lS) {
        res[i] = rS;
        i--;
        r--;
      } else {
        res[i] = lS;
        i--;
        l++;
      }
    }
    return res;
  }
};

int main() {
  vector<int> nums = {-4, -1, 0, 3, 10}; // Example input

  Solution sol;
  vector<int> result = sol.sortedSquares(nums);

  // Output the result
  cout << "Sorted squares: ";
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
