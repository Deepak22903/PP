#include <iostream>
#include <stack>
using namespace std;
string reverseVowels(string s) {
  stack<char> st;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
        s[i] == 'O' || s[i] == 'U') {
      st.push(s[i]);
    }
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
        s[i] == 'O' || s[i] == 'U') {
      s[i] = st.top();
      st.pop();
    }
  }
  return s;
}
int main(int argc, char *argv[]) {
  string s = "leetcode";
  string res = reverseVowels(s);
  cout << res << endl;

  return 0;
}
