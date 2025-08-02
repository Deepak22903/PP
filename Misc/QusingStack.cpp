#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Q {
public:
  stack<int> s1;
  stack<int> s2;

  void push(int val) { s1.push(val); }
  void pop() {
    if (s1.empty()) {
      s2.pop();
    } else {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
      s2.pop();
    }
  }
  int top() {
    if (s1.empty()) {
      return s2.top();
    } else {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
      return s2.top();
    }
  }
};

int main(int argc, char *argv[]) {
  Q q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.pop();
  cout << q.top() << endl;
  return 0;
}
