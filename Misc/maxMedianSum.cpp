#include <bits/stdc++.h>
#include <vector>

using namespace std;

int f(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  int n = nums.size() / 3;
  if (n == 0)
    return nums[0];
  int ind = nums.size() - 2;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += nums[ind];
    ind = ind - 2;
  }
  return sum;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << f(arr);
}
