#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    // Solution goes here
  }
};

int main() {
  int numRows = 5;

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
