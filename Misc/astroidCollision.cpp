#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> asteroidCollision(vector<int> &asteroids) {
  stack<int> is;

  for (auto val : asteroids) {
    if (is.empty() || val > 0 || is.top() < 0) {
      // No collision: push if stack empty, val is moving right, or top is also
      // moving left
      is.push(val);
    } else {
      // Collision case: val is negative and top is positive
      while (!is.empty() && is.top() > 0) {
        if (is.top() < -val) {
          is.pop(); // Top asteroid explodes, keep checking
        } else if (is.top() == -val) {
          is.pop(); // Both explode
          val = 0;  // Mark as destroyed
          break;
        } else {
          // Incoming asteroid is smaller, it explodes
          val = 0;
          break;
        }
      }
      if (val != 0) {
        is.push(val);
      }
    }
  }

  vector<int> res;
  while (!is.empty()) {
    res.push_back(is.top());
    is.pop();
  }
  reverse(res.begin(), res.end());
  return res;
}
int main(int argc, char *argv[]) {
  vector<int> arr{1, -2, -2, -2};
  vector<int> res{asteroidCollision(arr)};
  for (auto val : res) {
    cout << val << endl;
  }
  return 0;
}
