#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void subsetSum2(vector<int> &arr, int i, int n, vector<int> ds,
                vector<vector<int>> &res) {
  res.push_back(ds);

  for (int k = i; k < arr.size(); k++) {
    if (k > i && arr[k] == arr[k - 1])
      continue;

    ds.push_back(arr[k]);
    subsetSum2(arr, k + 1, n, ds, res);
    ds.pop_back();
  }
}

int main(int argc, char *argv[]) {
  vector<int> arr = {1, 2, 2};
  vector<vector<int>> res;
  subsetSum2(arr, 0, arr.size(), {}, res);

  for (auto it : res) {

    for (auto val : it) {

      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}
