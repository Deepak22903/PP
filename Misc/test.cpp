#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findMissingRepeatingNumbers(vector<int> nums) {
    vector<int> res;
    unordered_map<int, int> map;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      auto it = map.find(nums[i]);
      if (it != map.end())
        res.push_back(nums[i]);
      else
        map[nums[i]] = i;
    }
    vector<bool> bitmap(n + 1);
    for (int i = 0; i < nums.size(); i++) {
      bitmap[nums[i]] = 1;
    }
    for (int i = 1; i < bitmap.size(); i++) {
      if (bitmap[i] == 0)
        res.push_back(i);
    }

    return res;
  }
};

bool compareResults(vector<int> result, vector<int> expected) {
  sort(result.begin(), result.end());
  sort(expected.begin(), expected.end());
  return result == expected;
}

void runTest(const vector<int> &input, const vector<int> &expected,
             int testNum) {
  Solution sol;
  vector<int> result = sol.findMissingRepeatingNumbers(input);
  cout << "Test " << testNum << ": ";
  if (compareResults(result, expected)) {
    cout << "PASSED\n";
  } else {
    cout << "FAILED\n";
    cout << "Input: ";
    for (int num : input)
      cout << num << " ";
    cout << "\nExpected: ";
    for (int num : expected)
      cout << num << " ";
    cout << "\nGot: ";
    for (int num : result)
      cout << num << " ";
    cout << "\n";
  }
}

int main() {
  vector<pair<vector<int>, vector<int>>> tests = {
      {{1, 1}, {1, 2}},             // Min input size, missing 2
      {{2, 2}, {2, 1}},             // Duplicate 2, missing 1
      {{1, 2, 2, 4}, {2, 3}},       // Missing 3, repeating 2
      {{4, 3, 6, 2, 1, 1}, {1, 5}}, // Larger list
      {{1, 2, 3, 4, 4}, {4, 5}},    // Missing last
      {{3, 3, 1, 2, 5}, {3, 4}},    // Missing 4, repeating 3
      {{5, 4, 3, 2, 2}, {2, 1}},    // Reversed order
      {{1, 1, 3, 4, 5}, {1, 2}},    // Missing 2
      {{2, 3, 4, 5, 5}, {5, 1}},    // Missing 1
      {{1, 2, 3, 4, 5},
       {}}, // Valid input (no repetition, undefined behavior for this function)
      {{}, {}}, // Invalid: empty input (observe behavior)
  };

  for (int i = 0; i < tests.size(); ++i) {
    runTest(tests[i].first, tests[i].second, i + 1);
  }

  return 0;
}
