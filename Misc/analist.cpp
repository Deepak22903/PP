#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
vector<vector<string>> groupAnagrams(vector<string> &strs) {
  vector<vector<string>> res;
  multimap<string, string> mmap;
  for (int i = 0; i < strs.size(); i++) {
    string temp = strs[i];
    sort(temp.begin(), temp.end());
    mmap.insert({temp, strs[i]});
  }
  for (auto it = mmap.begin(); it != mmap.end();) {
    string key = it->first;
    auto range = mmap.equal_range(key);
    int i = 0;
    vector<string> temp;
    for (auto itr = range.first; itr != range.second; ++itr) {
      temp.push_back(itr->second);
    }
    res.push_back(temp);
    it = range.second;
  }
  return res;
}
int main() {
  vector<string> input = {"act", "pots", "tops", "cat", "stop", "hat"};
  vector<vector<string>> res = groupAnagrams(input);
  for (const auto &group : res) {
    // Iterate through each string in the current group
    for (const auto &word : group) {
      std::cout << word << " ";
    }
    // Newline after each group
    std::cout << std::endl;
  }
}
