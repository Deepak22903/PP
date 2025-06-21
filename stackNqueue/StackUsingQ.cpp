#include <bits/stdc++.h>
#include <queue>
using namespace std;

class SuQ {
private:
  queue<int> q;

public:
  void push(int val) {
    q.push(val);
    int sz = q.size();
    for (int i = 0; i < sz - 1; i++) {
      q.push(q.front());
      q.pop();
    }
  }
  void pop() {
    if (!q.empty())
      q.pop();
  }
  int top() { return q.front(); }
};
int main(int argc, char *argv[]) {
  SuQ st;
  st.push(1);
  st.push(2);
  st.push(3);
  cout << st.top() << endl;
  st.pop();
  cout << st.top() << endl;

  return 0;
}
