#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> threeSome(vector<int> arr) {
  vector<vector<int>> res{};
  int len = arr.size();
  if (len < 3)
    return {};
  for (int i = 0; i < len; i++) {
    if (i > 0 && arr[i] == arr[i - 1])
      continue;
    int target = -arr[i];
    int start = i + 1;
    int end = len - 1;
    unordered_map<int, int> map{};
    for (int k = start; k <= end; k++) {
      int complement = target - arr[k];
      if (map.find(complement) != map.end()) {
        res.push_back({arr[i], arr[k], complement});
      }
      map[arr[k]] = k;
    }
  }
  return res;
}

int main(int argc, char *argv[]) {
  vector<int> arr{4, 5, 2, 1, -1, 0, 0, -2, -3};
  vector<vector<int>> res{};
  res = threeSome(arr);
  for (auto vec : res) {
    cout << "Seq: \n";
    for (auto val : vec) {
      cout << val << endl;
    }
  }

  return 0;
}
