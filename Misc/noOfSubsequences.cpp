
#include <bits/stdc++.h>
using namespace std;

long long f(int sind, int pind, string &s, string &pattern,
            vector<vector<long long>> &dp, int insertPos, char insertedChar) {
  if (sind == 0) {
    char ch = (insertPos == 0 ? insertedChar : s[0]);
    if (pind == 0 && ch == pattern[0])
      return 1;
    else if (pind < 0)
      return 1;
    else
      return 0;
  }
  if (pind < 0)
    return 1;
  if (dp[sind][pind] != -1)
    return dp[sind][pind];

  char currentChar =
      (sind == insertPos ? insertedChar
                         : (sind < insertPos ? s[sind] : s[sind - 1]));

  long long notpick =
      f(sind - 1, pind, s, pattern, dp, insertPos, insertedChar);
  long long pick = 0;
  if (currentChar == pattern[pind])
    pick = f(sind - 1, pind - 1, s, pattern, dp, insertPos, insertedChar);

  return dp[sind][pind] = notpick + pick;
}

int main() {
  string s = "HI";
  string pattern = "LCT";
  long long maxi = 0;

  unordered_map<long long, long long> cache;

  for (int i = 0; i <= s.size(); i++) {
    for (int j = 0; j < pattern.size(); j++) {
      long long key = ((long long)i << 32) | j;
      if (cache.find(key) == cache.end()) {
        // dp size is original length + 1 because of the inserted char
        vector<vector<long long>> dp(s.size() + 1,
                                     vector<long long>(pattern.size(), -1));
        cache[key] =
            f(s.size(), pattern.size() - 1, s, pattern, dp, i, pattern[j]);
      }
      maxi = max(maxi, cache[key]);
    }
  }

  cout << maxi << endl;
  return 0;
}
