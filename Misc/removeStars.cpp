#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

string removeStars(string s) {
  stack<char> cs;
  for (auto val : s) {
    if (val == '*') {
      cs.pop();
      continue;
    }
    cs.push(val);
  }
  string res{};
  while (!cs.empty()) {
    char ch = cs.top();
    res += ch;
    cs.pop();
  }

  reverse(res.begin(), res.end());
  return res;
}
// string removeStars(string s) {
//   int len = s.size();
//   if (len == 1 && s[0] == '*')
//     return "";
//   for (int i = 0; i < len; i++) {
//     if (s[i] != '*')
//       continue;
//     s.erase(i, 1);
//     i--;
//     len--;
//     s.erase(i, 1);
//     i--;
//     len--;
//   }
//   return s;
// }
//
int main(int argc, char *argv[]) {
  string s = "leet**cod*e";
  cout << removeStars(s) << endl;
  return 0;
}
