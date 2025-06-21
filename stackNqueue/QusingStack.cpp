#include <bits/stdc++.h>
#include <stack>
using namespace std;

class QuS {
private:
  stack<int> s1;
  stack<int> s2;

public:
  void push(int val) {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
    s1.push(val);
    while (!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
  }
  void pop() { s1.pop(); }
  int front() { return s1.top(); }
};

int main(int argc, char *argv[]) {
  QuS q;
  q.push(1);
  q.push(2);
  cout << q.front() << endl;
  return 0;
}
