#include <bits/stdc++.h>
#include <stack>
#include <vector>

using namespace std;

vector<int> NGE(vector<int> arr) {
  stack<int> st;
  vector<int> res;
  for (int i = arr.size() - 1; i >= 0; i--) {
    if (st.empty()) {
      res.push_back(-1);
      st.push(arr[i]);
    } else {
      if (st.top() > arr[i]) {
        res.push_back(st.top());
        st.push(arr[i]);
      } else {
        while (!st.empty() && st.top() <= arr[i]) {
          st.pop();
        }
        if (st.empty())
          res.push_back(-1);
        else
          res.push_back(st.top());
        st.push(arr[i]);
      }
    }
  }
  reverse(res.begin(), res.end());
  return res;
}
int main() {
  vector<int> arr = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
  for (auto val : NGE(arr)) {
    cout << val << " ";
  }
}
