#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> ans;
    for (int i = 0; i <= n; i++) {
      int num = i;
      int ones = 0;
      while (num) {
        ones += num % 2;
        num = num / 2;
      }
      ans.push_back(ones);
    }
    return ans;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> arr;
  arr = s.countBits(5);
  for (int val : arr) {
    cout << val << " ";
  }
  return 0;
}
