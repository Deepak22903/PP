#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int longestSubarray(vector<int> &nums) {
  int len = nums.size();
  int res = INT_MIN;
  int l{};
  int m{};
  bool oneUsed = false;
  bool dirtyBit = false;
  int currMax{};
  while (m < len) {
    if (nums[m] == 0 && oneUsed) {
      dirtyBit = true;
      if (currMax > res) {
        res = currMax;
      }
      while (nums[l] != 0) {
        l++;
      }
      l++;
      oneUsed = false;
      currMax = m - l;
    }

    if (nums[m] == 0) {
      oneUsed = true;
      dirtyBit = true;
    }
    currMax++;
    m++;
  }

  if (currMax > res) {
    res = currMax;
  }
  if (!oneUsed && dirtyBit)
    res -= 2;
  else
    res--;
  return res;
}

int main(int argc, char *argv[]) {
  vector<int> arr{1, 1, 1};
  cout << longestSubarray(arr) << endl;

  return 0;
}
