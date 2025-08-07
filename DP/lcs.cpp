
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    string beeg, smol;
    if (text1.size() != text2.size()) {
      smol = text1.size() > text2.size() ? text2 : text1;
      beeg = text1.size() < text2.size() ? text2 : text1;
    } else {
      smol = text1;
      beeg = text2;
    }
    int res = 0;
    int i = 0, j = 0;
    int prev = -1;
    while (i < beeg.size()) {
      while (i < beeg.size() && beeg[i] != smol[j])
        i++;
      if (i == beeg.size() && j != smol.size()) {
        j++;
        if (prev != -1)
          i = prev;
        else
          i = 0;
      } else {
        if (j == smol.size())
          return res;
        i++;
        prev = i;
        j++;
        res++;
      }
    }
    return res;
  }
};
class solution {
public:
  int f(string &text1, string &text2, int ind1, int ind2,
        vector<vector<int>> &dp) {
    if (ind1 < 0 || ind2 < 0)
      return 0;
    if (dp[ind1][ind2] != -1)
      return dp[ind1][ind2];
    if (text1[ind1] == text2[ind2])
      return dp[ind1][ind2] = 1 + f(text1, text2, ind1 - 1, ind2 - 1, dp);
    return dp[ind1][ind2] = 0 + max(f(text1, text2, ind1 - 1, ind2, dp),
                                    f(text1, text2, ind1, ind2 - 1, dp));
  }
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
    return f(text1, text2, text1.size() - 1, text2.size() - 1, dp);
  }
};
int main() {
  Solution sol;

  // 1. Both strings are empty
  cout << "Test 1: " << sol.longestCommonSubsequence("", "") << " (Expected: 0)"
       << endl;

  // 2. One string is empty
  cout << "Test 2: " << sol.longestCommonSubsequence("abc", "")
       << " (Expected: 0)" << endl;
  cout << "Test 3: " << sol.longestCommonSubsequence("", "abc")
       << " (Expected: 0)" << endl;

  // 3. No characters in common
  cout << "Test 4: " << sol.longestCommonSubsequence("abc", "def")
       << " (Expected: 0)" << endl;

  // 4. Some common characters in correct order
  cout << "Test 5: " << sol.longestCommonSubsequence("abcde", "ace")
       << " (Expected: 3)" << endl;

  // 5. All characters match
  cout << "Test 6: " << sol.longestCommonSubsequence("abc", "abc")
       << " (Expected: 3)" << endl;

  // 6. All characters match but out of order
  cout << "Test 7: " << sol.longestCommonSubsequence("abc", "cba")
       << " (Expected: 1)" << endl;

  // 7. One character long inputs
  cout << "Test 8: " << sol.longestCommonSubsequence("a", "a")
       << " (Expected: 1)" << endl;
  cout << "Test 9: " << sol.longestCommonSubsequence("a", "b")
       << " (Expected: 0)" << endl;

  // 8. Long repeated characters
  cout << "Test 10: " << sol.longestCommonSubsequence("aaaaa", "aaa")
       << " (Expected: 3)" << endl;

  // 9. Long inputs (basic check, not performance)
  cout << "Test 11: " << sol.longestCommonSubsequence("abcdefghij", "cdgi")
       << " (Expected: 4)" << endl;

  return 0;
}
