#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> res;
    int colS = 0;
    int rowS = 0;
    int colE = matrix[0].size() - 1;
    int rowE = matrix.size() - 1;
    while (rowS <= rowE && colS <= colE) {
      for (int i = colS; i <= colE; i++) {
        res.push_back(matrix[rowS][i]);
      }
      rowS++;

      for (int i = rowS; i <= rowE; i++) {
        res.push_back(matrix[i][colE]);
      }
      colE--;
      if (rowS <= rowE) {
        for (int i = colE; i >= colS; i--) {
          res.push_back(matrix[rowE][i]);
        }
        rowE--;
      }

      if (colS <= colE) {
        for (int i = rowE; i >= rowS; i--) {
          res.push_back(matrix[i][colS]);
        }
        colS++;
      }
    }
    return res;
  }
}

;

int main() {
  Solution sol;
  vector<vector<int>> mat = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};
  for (int val : sol.spiralOrder(mat))
    cout << val << " ";
  cout << endl;
}
