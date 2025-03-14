#include <iostream>
#include <vector>

using namespace std;
void moveZeroes(vector<int> &nums) {
  int pos{};

  for (int val : nums) {
    if (val != 0) {
      nums[pos] = val;
      pos++;
    }
  }
  for (; pos < nums.size(); pos++) {
    nums[pos] = 0;
  }
}
// void moveZeroes(vector<int> &nums) {
//   int i{};
//   int len = nums.size();
//   int j = len - 1;
//   while (i < j) {
//     if (nums[j] == 0) {
//       j--;
//     } else if (nums[i] == 0) {
//       int temp = nums[i];
//       nums[i] = nums[j];
//       nums[j] = temp;
//       i++;
//       j--;
//     } else {
//       i++;
//     }
//   }
// }
//
int main(int argc, char *argv[]) {
  vector<int> arr{0, 1, 0, 3, 12};
  cout << "Before: \n";
  for (int val : arr) {
    cout << val << " ";
  }
  moveZeroes(arr);
  cout << "\nAfter: \n";

  for (int val : arr) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}
