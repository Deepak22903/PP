#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int longestOnes(vector<int> &nums, int k) {
  int l{};
  int m{};
  int len = nums.size();
  int maxOnes = INT_MIN;
  int currOnes = 0;
  while (m < len) {
    if (nums[m] == 0 && k == 0) {
      if (currOnes > maxOnes) {
        maxOnes = currOnes;
      }
      while (nums[l] != 0) {
        l++;
      }
      l++;
      k++;
      currOnes = (m - l);
    }

    if (nums[m] == 0 && k > 0) {
      k--;
    }
    currOnes++;
    m++;
  }

  if (currOnes > maxOnes) {
    maxOnes = currOnes;
  }
  return maxOnes;
}

int main(int argc, char *argv[]) {
  vector<int> arr{0, 0, 1, 1, 1, 0, 0};
  cout << longestOnes(arr, 0) << endl;
  return 0;
}
