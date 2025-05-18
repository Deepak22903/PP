#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    // Solution goes here
    vector<vector<int>> matrix;
    for (int i = 0; i < numRows; i++) {
      if (matrix.size() == 0) {
        matrix.push_back({1});
      } else if (matrix.size() == 1) {
        matrix.push_back({1, 1});
      } else {
        vector<int> curr;
        vector<int> prev = matrix[i - 1];
        curr.push_back(1);
        // sliding window
        for (int j = 0; j < prev.size() - 1; j++) {
          curr.push_back(prev[j] + prev[j + 1]);
        }

        // sliding window ends
        curr.push_back(1);
        matrix.push_back(curr);
      }
    }
    return matrix;
  }
};

int main() {
  int numRows = 30;

  Solution sol;
  vector<vector<int>> result = sol.generate(numRows);

  // Output the result
  for (const auto &row : result) {
    for (int val : row) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}
