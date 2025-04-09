#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int maxOperations(vector<int> &nums, int k) {
  int len = nums.size();
  sort(nums.begin(), nums.end());
  int i = 0;
  int j = len - 1;
  int res{};
  while (i < j) {
    if (nums[i] + nums[j] == k) {
      nums[i] = INT_MAX;
      nums[j] = INT_MAX;
      i++;
      j--;
      res++;
    } else if (nums[i] + nums[j] > k) {
      j--;
    } else {
      i++;
    }
  }
  return res;
}

int main(int argc, char *argv[]) {
  vector<int> arr{3, 1, 3, 4, 3};
  cout << maxOperations(arr, 6);
  return 0;
}
