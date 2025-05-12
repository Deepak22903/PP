#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    char carry = '0';
    string res{};
    int len = max(a.size(), b.size());
    a = string(len - a.size(), '0') + a;
    b = string(len - b.size(), '0') + b;
    cout << a << endl << b << endl;
    for (int i = len - 1; i >= 0; i--) {
      if (a[i] == '0' && b[i] == '0') {
        if (carry == '0') {
          res += "0";
        } else {
          res += "1";
          carry = '0';
        }
      } else if (a[i] == '0' && b[i] == '1' || a[i] == '1' && b[i] == '0') {
        if (carry == '0') {
          res += "1";
        } else {
          res += "0";
          carry = '1';
        }
      } else {
        if (carry == '0') {
          res += "0";
          carry = '1';
        } else {
          res += "1";
          carry = '1';
        }
      }
    }
    if (carry == '1')
      res += "1";
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution solution;
  string a = "101";
  string b = "10";
  string result = solution.addBinary(a, b);
  cout << "Result: " << result << endl;
  return 0;
}
