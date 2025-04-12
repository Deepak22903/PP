#include <cctype>
#include <iostream>
#include <stack>
using namespace std;
string decodeString(string s) {
  stack<int> ns;
  stack<string> ss;
  string res = "";
  string curr = "";
  int num = 0;

  for (int i = 0; i < s.size(); i++) {
    if (isdigit(s[i])) {
      num = num * 10 + (s[i] - '0'); // support multi-digit numbers
    } else if (s[i] == '[') {
      ns.push(num);
      ss.push(res);
      res = "";
      num = 0;
    } else if (s[i] == ']') {
      int repeat = ns.top();
      ns.pop();
      string prev = ss.top();
      ss.pop();
      string temp = "";
      for (int j = 0; j < repeat; j++) {
        temp += res;
      }
      res = prev + temp;
    } else {
      res += s[i];
    }
  }
  return res;
}

int main(int argc, char *argv[]) {
  string s = "3[a2[c]]";
  cout << decodeString(s) << endl;
  return 0;
}
