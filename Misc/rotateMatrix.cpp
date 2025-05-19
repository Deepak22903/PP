#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    // Solution goes here
  }
};

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  Solution sol;
  sol.rotate(matrix);

  // Output the rotated matrix
  for (const auto &row : matrix) {
    for (int val : row) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}
