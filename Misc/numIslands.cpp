#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> findCords(vector<vector<char>> &grid) {
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1')
          return {i, j};
      }
    }
    return {};
  }

public:
  int numIslands(vector<vector<char>> &grid) {
    // Solution goes here
    int res = 0;
    int rows = grid.size() - 1;
    int cols = grid[0].size() - 1;
    vector<int> cords(2);
    while (!findCords(grid).empty()) {
      cords = findCords(grid);
      stack<vector<int>> cordStack;
      cordStack.push(cords);
      while (!cordStack.empty()) {
        vector<int> curr = cordStack.top();
        cordStack.pop();
        int i = curr[0];
        int j = curr[1];
        grid[i][j] = '0';
        if (j < cols && grid[i][j + 1] == '1')
          cordStack.push({i, j + 1});
        if (i < rows && grid[i + 1][j] == '1')
          cordStack.push({i + 1, j});
        if (i > 0 && grid[i - 1][j] == '1')
          cordStack.push({i - 1, j});
        if (j > 0 && grid[i][j - 1] == '1')
          cordStack.push({i, j - 1});
      }
      res++;
    }
    return res;
  }
};

int main() {
  vector<vector<char>> grid = {
      {'1', '1', '1'}, {'0', '1', '0'}, {'1', '1', '1'}};

  Solution sol;
  int count = sol.numIslands(grid);

  cout << "Number of islands: " << count << endl;

  return 0;
}
