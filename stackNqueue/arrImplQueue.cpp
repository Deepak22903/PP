#include <bits/stdc++.h>

using namespace std;

class Queue {
private:
  static const int size = 4;
  int q[size];
  int currSize = 0;
  int front = -1;
  int rear = -1;

public:
  void push(int val) {
    if ((rear + 1) % size == front) {
      cout << "error" << endl;
      return;
    }
    if (currSize == 0) {
      front = rear = 0;
      q[rear] = val;
    } else {
      rear = (rear + 1) % size;
      q[rear] = val;
    }
    currSize++;
  }
  void pop() {
    if (currSize == 0) {
      cout << "error" << endl;
      return;
    }
    if (currSize == 1)
      front = rear = -1;
    else
      front = (front + 1) % size;
    currSize--;
  }
  int top() { return q[front]; }
  int getSize() { return currSize; }
};

int main() {
  Queue que;
  que.push(5);
  que.push(2);
  que.push(3);
  que.push(4);
  que.pop();
  que.push(6);

  cout << que.top() << endl;
  cout << que.getSize() << endl;
}
