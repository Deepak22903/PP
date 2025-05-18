#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    // Solution goes here
    map<vector<int>, int> zeroArr;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == 0) {
          zeroArr[{i, j}] = i;
        }
      }
    }
    for (auto val : zeroArr) {
      vector<int> arr = val.first;
      for (int i = 0; i < matrix[0].size(); i++) {
        matrix[arr[0]][i] = 0;
      }
      for (int j = 0; j < matrix.size(); j++) {
        matrix[j][arr[1]] = 0;
      }
    }
  }
};

int main() {
  vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

  Solution sol;
  sol.setZeroes(matrix);

  // Output the matrix
  for (const auto &row : matrix) {
    for (int val : row) {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}
