#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int f1(string &s, int ind, vector<int> &dp) {
    if (ind < 0)
      return 1; // reached before start => valid path

    if (dp[ind] != -1)
      return dp[ind];

    int one = 0, two = 0;

    // Single-digit decode (only if not '0')
    if (s[ind] != '0')
      one = f1(s, ind - 1, dp);

    // Two-digit decode (only if valid 10..26)
    if (ind > 0 && s[ind - 1] != '0') {
      int n = (s[ind - 1] - '0') * 10 + (s[ind] - '0');
      if (n >= 10 && n <= 26)
        two = f1(s, ind - 2, dp);
    }

    return dp[ind] = one + two;
  }

  int numDecodings(string s) {
    if (s.empty())
      return 0;

    vector<int> dp(s.size(), -1);
    return f1(s, s.size() - 1, dp);
  }
};

void f(string &s, int ind, int &cnt) {

  if (s[ind] > '0' && ind < s.size()) {
    cnt++;
    f(s, ind + 1, cnt);
  }
  int n = 0;
  for (int i = ind; i < s.size(); i++) {
    n = n * 10 + s[i];
    if (n > 0 && n < 27) {
      cnt++;
      f(s, i + 1, cnt);
    }
  }
}
int main() {
  Solution sol;

  vector<pair<string, int>> tests = {
      {"12", 2},               // "AB", "L"
      {"226", 3},              // "BZ", "VF", "BBF"
      {"06", 0},               // invalid
      {"10", 1},               // "J"
      {"27", 1},               // "BG"
      {"11106", 2},            // "AAJF", "KJF"
      {"1", 1},                // "A"
      {"0", 0},                // invalid
      {"2101", 1},             // "U A"
      {"2611055971756562", 4}, // tricky
      {"12121", 8},            // many combos
      {"20419", 1},            // zeros handled
      {"9012", 0}              // invalid at start
  };

  for (auto &[s, expected] : tests) {
    int result = sol.numDecodings(s);
    cout << "Input: \"" << s << "\" -> Output: " << result
         << " | Expected: " << expected << (result == expected ? " ✅" : " ❌")
         << '\n';
  }

  return 0;
}
