#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
bool uniqueOccurrences(vector<int> &arr) {
  unordered_map<int, int> map;
  for (auto val : arr) {
    auto it = map.find(val);
    if (it == map.end()) {
      map[val] = 1;
    } else {
      it->second++;
    }
  }
  unordered_map<int, int> dupCheck;
  for (auto it : map) {
    auto itr = dupCheck.find(it.second);
    if (itr != dupCheck.end()) {
      return false;
    } else {
      dupCheck[it.second] = 1;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  vector<int> arr{1, 2, 2};
  cout << uniqueOccurrences(arr) << endl;

  return 0;
}
