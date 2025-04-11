#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
  vector<vector<int>> res(2);
  unordered_map<int, int> map1;
  unordered_map<int, int> map2;
  for (int val : nums2) {
    map2[val] = 1;
  }
  for (int i = 0; i < nums1.size(); i++) {
    auto it = map2.find(nums1[i]);
    if (it == map2.end()) {
      if (std::find(res[0].begin(), res[0].end(), nums1[i]) == res[0].end()) {
        res[0].push_back(nums1[i]);
      }
    }
  }
  for (int val : nums1) {
    map1[val] = 1;
  }
  for (int i = 0; i < nums2.size(); i++) {
    auto it = map1.find(nums2[i]);
    if (it == map1.end()) {
      if (std::find(res[1].begin(), res[1].end(), nums2[i]) == res[1].end()) {
        res[1].push_back(nums2[i]);
      }
    }
  }
  return res;
}

int main(int argc, char *argv[]) {
  vector<int> arr1{1, 2, 3, 3};
  vector<int> arr2{1, 1, 2, 2};

  for (auto it : findDifference(arr1, arr2)) {
    cout << "[ ";
    for (int val : it) {
      cout << val << ", ";
    }
    cout << " ]\n";
  }

  return 0;
}
