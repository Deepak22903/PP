#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n) {
  vector<int> ans(n + 1);
  ans[0] = 0;
  for (int i = 1; i <= n; i++) {
    ans[i] = ans[i / 2] + i % 2;
  }
  return ans;
}

int main(int argc, char *argv[]) {
  vector<int> s = countBits(2);
  for (int val : s) {
    cout << val << " ";
  }
  return 0;
}
