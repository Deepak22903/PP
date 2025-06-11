#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void subsetSum(vector<int> &arr, int i, int n, vector<int> ds,
               vector<vector<int>> &res) {
  if (i >= n) {
    res.push_back(ds);
    return;
  }

  ds.push_back(arr[i]);
  subsetSum(arr, i + 1, n, ds, res);
  ds.pop_back();

  subsetSum(arr, i + 1, n, ds, res);
}

int main(int argc, char *argv[]) {
  vector<int> arr = {1, 2, 3};
  vector<vector<int>> res;
  subsetSum(arr, 0, arr.size(), {}, res);

  for (auto it : res) {

    for (auto val : it) {

      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}
