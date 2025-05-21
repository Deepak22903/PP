#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    for (int i = m; i < (m + n); i++) {
      nums1[i] = nums2[i - m];
    }
    sort(nums1.begin(), nums1.end());
  }
  // void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
  //   // Solution goes here
  //   int i{};
  //   int j{};
  //   while (i < (m + n) && j < n) {
  //     if (nums1[i] >= nums2[j] || nums1[i] == 0) {
  //       int ele = nums1[i];
  //       swap(nums1[i], nums2[j]);
  //       if (ele == 0)
  //         j++;
  //       i++;
  //     } else {
  //       i++;
  //     }
  //   }
  // }
};

int main() {
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m = 3;

  vector<int> nums2 = {2, 5, 6};
  int n = 3;

  Solution sol;
  sol.merge(nums1, m, nums2, n);

  // Output the merged nums1
  for (int num : nums1) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
