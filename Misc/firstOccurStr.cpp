#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() > haystack.size())
      return -1;
    if (haystack.size() == needle.size()) {
      if (haystack == needle) {
        return 0;
      } else {
        return -1;
      }
    }
    int i{};
    int winSize = needle.size();
    while (i <= haystack.size() - winSize) {
      string str = haystack.substr(i, winSize);
      if (str == needle)
        return i;
      i++;
    }
    return -1;
  }

  // int strStr(string haystack, string needle) {
  //   int i{}, j{};
  //   int index{};
  //   bool dirty = false;
  //   while (i < haystack.size()) {
  //     if (haystack[i] == needle[j]) {
  //       if (!dirty) {
  //         dirty = true;
  //         index = i;
  //       }
  //       i++;
  //       j++;
  //       if (j == needle.size())
  //         return index;
  //     } else {
  //       dirty = false;
  //       j = 0;
  //       i++;
  //     }
  //   }
  //   return -1;
  // }
};

int main() {
  Solution sol;
  string haystack = "aaa";
  string needle = "aaaa";
  int index = sol.strStr(haystack, needle);
  cout << "Index: " << index << endl;
  return 0;
}
