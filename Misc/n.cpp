#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
  vector<string> strs = {"act", "pots", "tops", "cat", "stop", "hat"};
  multimap<string, string> mmap;
  for (int i = 0; i < strs.size(); i++) {
    string temp = strs[i];
    sort(temp.begin(), temp.end());
    mmap.insert({temp, strs[i]});
  }
  for (const auto &it : mmap) {
    cout << it.first << " : " << it.second << "\n";
  }
}
