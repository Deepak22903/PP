#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pascal(int n) {
  vector<vector<int>> res;
  if (n == 0)
    return {};
  if (n == 1)
    return {{1}};
  if (n == 2)
    return {{1}, {1, 1}};
  res.push_back({1});
  res.push_back({1, 1});
  vector<int> prev = {1, 1};
  n = n - 2;
  for (int i = 0; i < n; i++) {
    vector<int> curr;
    curr.push_back(1);
    for (int j = 0; j < prev.size() - 1; j++) {
      curr.push_back(prev[j] + prev[j + 1]);
    }
    curr.push_back(1);
    prev = curr;
    res.push_back(curr);
  }
  return res;
}

int main() {
  vector<vector<int>> res = pascal(5);
  for (auto v : res) {
    for (auto e : v) {
      cout << e << " ";
    }
    cout << endl;
  }
}
