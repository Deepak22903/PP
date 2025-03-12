#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
  vector<int> res;

  unordered_map<int, int> map;
  int prod{1};
  for (int i = 0; i < nums.size(); i++) {
    map[i] = prod;
    prod = prod * nums[i];
  }
  prod = 1;
  for (int i = nums.size() - 1; i >= 0; i--) {
    map[-(i + 1)] = prod;
    prod = prod * nums[i];
  }
  for (int i = 0; i < nums.size(); i++) {
    res.push_back(map[i] * map[-(i + 1)]); // Combine prefix and suffix
  }
  return res;
}
int main(int argc, char *argv[]) {
  vector<int> n{1, 2, 3, 4};
  vector<int> res = productExceptSelf(n);
  for (int val : res) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}
