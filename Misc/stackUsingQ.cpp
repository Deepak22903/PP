#include <bits/stdc++.h>
#include <queue>
using namespace std;

class st {
public:
  queue<int> q;

  void push(int val) {
    q.push(val);
    for (int i = 0; i < q.size() - 1; i++) {
      q.push(q.front());
      q.pop();
    }
  }

  void pop() { q.pop(); }

  int top() { return q.front(); }
};

int main(int argc, char *argv[]) {
  st s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.pop();
  s.pop();
  s.pop();
  cout << s.top() << endl;
  return 0;
}
