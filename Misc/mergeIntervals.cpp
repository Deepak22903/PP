
#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    // Solution goes here
    if (intervals.empty())
      return {{}, {}};
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size() - 1; i++) {
      if (intervals[i + 1][0] <= intervals[i][1]) {
        int start = intervals[i][0];
        int end = intervals[i][1];
        while (i < intervals.size() - 1 && intervals[i + 1][0] <= end) {
          i++;
          end = max(end, intervals[i][1]);
        }
        res.push_back({start, end});
      } else {
        res.push_back({intervals[i][0], intervals[i][1]});
      }
    }
    if (res.empty() || res.back()[1] < intervals.back()[0]) {
      res.push_back(intervals.back());
    }

    return res;
  }
};

bool areEqual(const vector<vector<int>> &a, const vector<vector<int>> &b) {
  if (a.size() != b.size())
    return false;
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i].size() != b[i].size())
      return false;
    for (size_t j = 0; j < a[i].size(); ++j) {
      if (a[i][j] != b[i][j])
        return false;
    }
  }
  return true;
}

void runTest(vector<vector<int>> input, vector<vector<int>> expected,
             int testNumber) {
  Solution sol;
  vector<vector<int>> output = sol.merge(input);

  // Sort output and expected to ignore order differences
  sort(output.begin(), output.end());
  sort(expected.begin(), expected.end());

  cout << "Test " << testNumber << ": ";
  if (areEqual(output, expected)) {
    cout << "PASSED\n";
  } else {
    cout << "FAILED\n";
    cout << "Expected: ";
    for (const auto &v : expected)
      cout << "[" << v[0] << "," << v[1] << "] ";
    cout << "\nGot     : ";
    for (const auto &v : output)
      cout << "[" << v[0] << "," << v[1] << "] ";
    cout << "\n";
  }
}

int main() {
  vector<pair<vector<vector<int>>, vector<vector<int>>>> tests = {
      // Normal merge case
      {{{1, 3}, {2, 6}, {8, 10}, {15, 18}}, {{1, 6}, {8, 10}, {15, 18}}},

      // Fully overlapping intervals
      {{{1, 4}, {2, 3}}, {{1, 4}}},

      // No overlap
      {{{1, 2}, {3, 4}, {5, 6}}, {{1, 2}, {3, 4}, {5, 6}}},

      // Single interval
      {{{1, 10}}, {{1, 10}}},

      // All identical intervals
      {{{1, 1}, {1, 1}, {1, 1}}, {{1, 1}}},

      // Touching intervals (edge contact)
      {{{1, 2}, {2, 3}, {3, 4}}, {{1, 4}}},

      // Unsorted input
      {{{5, 6}, {1, 3}, {2, 4}}, {{1, 4}, {5, 6}}},

      // Empty input
      // {{}, {}},

      // Interval with zero-length
      {{{1, 1}, {2, 2}}, {{1, 1}, {2, 2}}}};

  for (size_t i = 0; i < tests.size(); ++i) {
    runTest(tests[i].first, tests[i].second, i + 1);
  }

  return 0;
}
