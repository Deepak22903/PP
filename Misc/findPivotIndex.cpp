#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int pivotIndex(vector<int> &nums) {
  unordered_map<int, int> map;
  int sum{};
  for (int i = 0; i < nums.size(); i++) {
    sum = sum + nums[i];
    map[i + 1] = sum;
  }
  sum = 0;
  for (int i = nums.size() - 1; i >= 0; i--) {
    sum = sum + nums[i];
    map[-(i + 1)] = sum;
  }
  for (int i = 0; i < nums.size(); i++) {
    if (i == 0 && map[-((i + 1) + 1)] == 0) {
      return 0;
    }
    if (i == nums.size() - 1 && map[(i + 1) - 1] == 0)
      return 0;
    if (map[(i + 1) - 1] == map[-((i + 1) + 1)]) {
      return i;
    }
  }
  return -1;
}
int main(int argc, char *argv[]) {
  vector<int> arr{2, 1, -1};
  int res = pivotIndex(arr);
  cout << res << endl;
  return 0;
}
