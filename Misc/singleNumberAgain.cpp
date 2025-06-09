#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int res = 0;
    for (auto val : nums) {
      res ^= val;
    }
    return res;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {2, 2, 1};
  int result = sol.singleNumber(nums);
  cout << "Single number is: " << result << endl;
  return 0;
}
