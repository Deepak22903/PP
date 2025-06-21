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
int main(int argc, char *argv[]) {
  string inf = "A+((B+C)*(D+E))";
  string pos;
  int i = 0;
  stack<char> st;
  while (i < inf.size()) {
    if (isalnum(inf[i]))
      pos += inf[i];
    else if (inf[i] == '(')
      st.push(inf[i]);
    else if (inf[i] == ')') {
      while (!st.empty() && st.top() != '(') {
        pos += st.top();
        st.pop();
      }
      st.pop();
    } else {
      while (!st.empty() && priority(inf[i]) < priority(st.top())) {
        pos += st.top();
        st.pop();
      }
      st.push(inf[i]);
    }
    i++;
  }
  while (!st.empty()) {
    pos += st.top();
    st.pop();
  }
  cout << pos << endl;
  return 0;
}
