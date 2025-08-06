#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++) {
      int target = -nums[i];
      unordered_map<int, int> mp;
      set<vector<int>> st;
      for (auto it : st) {
        res.push_back(it);
      }

      for (int j = +1; j < nums.size(); j++) {
        if (i != j) {
          int comp = target - nums[j];
          auto it = mp.find(comp);
          if (it != mp.end() && it->second != j && it->second != i) {
            res.push_back({nums[i], nums[j], nums[it->second]});
          }
          mp[nums[j]] = j;
        }
      }
    }
    return res;
  }
};

class solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> res;
    if (matrix.empty() || matrix[0].empty()) {
      return res;
    }

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
      // 1. Traverse Right
      for (int i = left; i <= right; ++i) {
        res.push_back(matrix[top][i]);
      }
      top++;

      // 2. Traverse Down
      for (int i = top; i <= bottom; ++i) {
        res.push_back(matrix[i][right]);
      }
      right--;

      // 3. Traverse Left (check if row still exists)
      if (top <= bottom) {
        for (int i = right; i >= left; --i) {
          res.push_back(matrix[bottom][i]);
        }
        bottom--;
      }

      // 4. Traverse Up (check if column still exists)
      if (left <= right) {
        for (int i = bottom; i >= top; --i) {
          res.push_back(matrix[i][left]);
        }
        left++;
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> mat = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}};

  // To get the correct full spiral, the matrix should have more rows.
  // Let's use a more illustrative example:
  vector<vector<int>> mat2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  cout << "Original Code's Matrix Output:" << endl;
  for (int val : sol.spiralOrder(mat)) { // Using your original matrix
    cout << val << " ";
  }
  cout << endl;

  cout << "\nCorrected Code's Matrix Output:" << endl;
  for (int val : sol.spiralOrder(mat2)) { // Using a better example matrix
    cout << val << " ";
  }
  cout << endl;
  // Expected Output: 1 2 3 4 8 12 11 10 9 5 6 7
}
