#include <bits/stdc++.h>

using namespace std;

class arrImpl {
private:
  int top;
  int arr[10];

public:
  arrImpl() { top = -1; }
  void push(int val) {
    if (top >= 10)
      cout << "err" << endl;
    top++;
    arr[top] = val;
  }
  int topElem() {
    if (top == -1 || top >= 10)
      cout << "err" << endl;
    return arr[top];
  }
  void pop() {
    if (top == -1)
      cout << "err" << endl;
    top--;
  }
  int size() {
    if (top == -1)
      return 0;
    return top + 1;
  }
};

int main() {
  arrImpl st;
  st.push(10);
  cout << st.topElem() << endl;
  cout << st.size() << endl;
  st.push(20);
  st.push(30);
  cout << st.size() << endl;
  st.pop();
  cout << st.topElem() << endl;
}
