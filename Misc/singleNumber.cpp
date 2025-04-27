#include <iostream>
#include <vector>
using namespace std;
// int singleNumber(vector<int> &nums) {
//   int res{};
//   bool dirty = false;
//   for (int i = 0; i < nums.size(); i++) {
//     for (int j = i + 1; j < nums.size(); j++) {
//       if ((nums[i] ^ nums[j]) == 0) {
//         dirty = true;
//         nums.erase(nums.begin() + j);
//       }
//     }
//     if (dirty != true) {
//       return nums[i];
//     }
//     dirty = false;
//   }
//   return -1;
// }

int singleNumber(vector<int> &nums) {
  int ans{};
  for (int val : nums) {
    ans = ans ^ val;
  }
  return ans;
}

int main(int argc, char *argv[]) {
  vector<int> arr = {2, 2, 1, 1, 5, 3, 3};
  int sn = singleNumber(arr);
  cout << sn << endl;
  return 0;
}
