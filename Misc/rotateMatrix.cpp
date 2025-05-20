#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    // Solution goes here
    vector<int> data;
    for (auto vec : matrix) {
      for (int ele : vec) {
        data.push_back(ele);
      }
    }
    int index = 0;
    for (int i = matrix.size() - 1; i >= 0; i--) {
      for (int j = 0; j < matrix.size(); j++) {
        matrix[j][i] = data[index];
        index++;
      }
    }
  }
};

int main() {
  vector<vector<int>> matrix = {
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

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
