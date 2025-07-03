#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    int res = 0;
    sort(intervals.begin(), intervals.end(),
         [](const auto &a, const auto &b) { return a[1] < b[1]; });
    for (int i = 0, j = 1; j < intervals.size(); i++, j++) {
      if (intervals[j][0] < intervals[i][1]) {
        res++;
        i--;
      } else {
        i = j;
        i--;
      }
    }
    return res;
  }
};

int main() {
  Solution sol;

  // Example input: overlapping intervals
  vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};

  int result = sol.eraseOverlapIntervals(intervals);
  cout << "Minimum number of intervals to remove: " << result << endl;

  return 0;
}
