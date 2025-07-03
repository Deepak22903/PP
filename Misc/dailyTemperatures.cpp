#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<pair<int, int>> st;
    vector<int> res(temperatures.size());
    for (int i = temperatures.size() - 1; i >= 0; i--) {
      while (!st.empty() && st.top().first <= temperatures[i])
        st.pop();
      if (st.empty())
        res[i] = 0;
      else
        res[i] = st.top().second - i;
      st.push({temperatures[i], i});
    }
    return res;
  }
};

int main() {
  vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

  Solution sol;
  vector<int> result = sol.dailyTemperatures(temperatures);

  cout << "Result: ";
  for (int days : result) {
    cout << days << " ";
  }
  cout << endl;

  return 0;
}
