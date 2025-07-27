#include <bits/stdc++.h>
#include <vector>

using namespace std;

int calc(vector<int> &nums, int c) {
  vector<bool> trashed(nums.size(), false);
  sort(nums.begin(), nums.end());
  int mul = 1;
  int i = nums.size() - 1;
  while (i >= 0) {
    while (i >= 0 && nums[i] > c)
      i--;
    if (i < 0)
      return nums.size();
    trashed[i] = true;
    mul *= 2;
    break;
  }

  for (int ind = i - 1; ind >= 0; ind--) {
    if (nums[ind] * mul <= c) {
      trashed[ind] = true;
      mul *= 2;
    }
  }
  int res = 0;
  for (int i = 0; i < trashed.size(); i++) {
    if (!trashed[i])
      res++;
  }
  return res;
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    int n, c;
    cin >> n >> c;
    vector<int> arr;
    for (int j = 0; j < n; j++) {
      int val;
      cin >> val;
      arr.push_back(val);
    }
    cout << calc(arr, c) << endl;
  }
}
