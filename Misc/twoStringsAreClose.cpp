#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

bool closeStrings(string word1, string word2) {
  if (word1.size() != word2.size())
    return false;
  unordered_map<char, int> map1;
  unordered_map<char, int> map2;

  for (auto val : word1) {
    auto it = map1.find(val);
    if (it == map1.end())
      map1[val] = 1;
    else
      map1[val]++;
  }

  for (auto val : word2) {
    auto it = map2.find(val);
    if (it == map2.end())
      map2[val] = 1;
    else
      map2[val]++;
  }

  if (map1.size() != map2.size())
    return false;

  for (auto it = map1.begin(); it != map1.end(); ++it) {
    auto itr = map2.find(it->first);
    if (itr == map2.end())
      return false;
  }

  // Compare value distributions
  unordered_map<int, int> freqCount1, freqCount2;

  for (const auto &[_, val] : map1) {
    freqCount1[val]++;
  }

  for (const auto &[_, val] : map2) {
    freqCount2[val]++;
  }

  if (freqCount1 != freqCount2)
    return false;
  return true;
}

int main(int argc, char *argv[]) {
  string w1 = "abc";
  string w2 = "bca";
  cout << closeStrings(w1, w2) << endl;
  return 0;
}
