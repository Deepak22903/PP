#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void subsetSum(vector<int> &arr, int i, int n, int sum, vector<int> &res) {
  if (i >= n) {
    res.push_back(sum);
    return;
  }
  subsetSum(arr, i + 1, n, sum + arr[i], res);

  subsetSum(arr, i + 1, n, sum, res);
}

int main(int argc, char *argv[]) {
  vector<int> arr = {5, 2, 1};
  vector<int> res;
  subsetSum(arr, 0, arr.size(), 0, res);
  sort(res.begin(), res.end());
  for (auto it : res)
    cout << it << " ";

  return 0;
}
