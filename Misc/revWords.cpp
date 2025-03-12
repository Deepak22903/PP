#include <iostream>
#include <stack>
#include <string>
using namespace std;
string reverseWords(string s) {
  stack<string> st;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') {
      if (i != 0)
        st.push(" ");
      while (s[i] == ' ') {
        i++;
      }
      i--;
    } else {
      string word{};
      for (; s[i] != ' ' && i < s.size(); i++) {
        word = word + s[i];
      }
      st.push(word);
      i--;
    }
  }

  while (st.top() == " ") {
    st.pop();
  }
  string res;
  while (!st.empty()) {
    res = res + st.top();
    st.pop();
  }
  return res;
}
int main(int argc, char *argv[]) {
  string s = "the sky is blue";
  string res = reverseWords(s);
  cout << res << endl;

  return 0;
}
