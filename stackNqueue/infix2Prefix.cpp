#include <bits/stdc++.h>
using namespace std;

int priority(char ch) {
  if (ch == '^')
    return 3;
  else if (ch == '*' || ch == '/')
    return 2;
  else if (ch == '+' || ch == '-')
    return 1;
  else
    return -1;
}
string convert(string s) {
  string res{};
  int beg = 0;
  int end = s.size() - 1;
  while (beg < end) {
    swap(s[beg], s[end]);
    if (s[beg] == '(')
      s[beg] = ')';
    else if (s[beg] == ')')
      s[beg] = '(';
    if (s[end] == '(')
      s[end] = ')';
    else if (s[end] == ')')
      s[end] = '(';
    beg++;
    end--;
  }
  int i = 0;
  stack<char> st;
  while (i < s.size()) {
    if (isalnum(s[i])) {
      res += s[i];
    } else if (s[i] == '(')
      st.push(s[i]);
    else if (s[i] == ')') {
      while (!st.empty() && st.top() != '(') {
        res += st.top();
        st.pop();
      }
      st.pop();
    } else {
      if (s[i] == '^') {
        while (!st.empty() && priority(s[i]) <= priority(st.top())) {
          res += st.top();
          st.pop();
        }
      } else
        while (!st.empty() && priority(s[i]) < priority(st.top()) &&
               st.top() != '(') {
          res += st.top();
          st.pop();
        }
      st.push(s[i]);
    }
    i++;
  }
  while (!st.empty()) {
    res += st.top();
    st.pop();
  }

  reverse(res.begin(), res.end());
  return res;
}

int main(int argc, char *argv[]) {
  string s = "(A+B)*C-D+F";
  cout << convert(s) << endl;
  return 0;
}
