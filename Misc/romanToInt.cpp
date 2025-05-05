#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    // Your implementation goes here
    int len = s.size();
    int res = 0;
    for (int i = len - 1; i >= 0; i--) {
      if (s[i] == 'I') {
        res += 1;
      } else if (s[i] == 'V') {
        if (i > 0 && s[i - 1] == 'I') {
          res += 4;
          i--;
        } else {
          res += 5;
        }
      } else if (s[i] == 'X') {
        if (i > 0 && s[i - 1] == 'I') {
          res += 9;
          i--;
        } else {
          res += 10;
        }
      } else if (s[i] == 'L') {
        if (i > 0 && s[i - 1] == 'X') {
          res += 40;
          i--;
        } else {
          res += 50;
        }
      } else if (s[i] == 'C') {
        if (i > 0 && s[i - 1] == 'X') {
          res += 90;
          i--;
        } else {
          res += 100;
        }
      } else if (s[i] == 'D') {
        if (i > 0 && s[i - 1] == 'C') {
          res += 400;
          i--;
        } else {
          res += 500;
        }
      } else if (s[i] == 'M') {
        if (i > 0 && s[i - 1] == 'C') {
          res += 900;
          i--;
        } else {
          res += 1000;
        }
      }
    }

    return res; // placeholder
  }
};

int main() {
  Solution sol;
  vector<pair<string, int>> testCases = {
      {"III", 3},        {"IV", 4},  {"IX", 9},       {"LVIII", 58},
      {"MCMXCIV", 1994}, {"XL", 40}, {"CDXLIV", 444}, {"MMXXV", 2025}};

  for (const auto &test : testCases) {
    int result = sol.romanToInt(test.first);
    cout << "romanToInt(\"" << test.first << "\") = " << result;
    if (result == test.second) {
      cout << " [PASS]";
    } else {
      cout << " [FAIL] (Expected " << test.second << ")";
    }
    cout << endl;
  }
  // cout << sol.romanToInt("MMXXV") << endl;

  return 0;
}
