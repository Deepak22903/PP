#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  void bfs(int n, int m, int r, int c, vector<vector<int>> &heights,
           vector<bool> &check, vector<vector<int>> &res, vector<int> &dr,
           vector<int> &dc) {

    queue<vector<int>> q;

    q.push({r, c, heights[r][c]});
    while (!q.empty()) {
      vector<int> curr = q.front();
      if (curr[1] == 0 || curr[0] == 0)
        check[0] = true;
      if (curr[0] == n - 1 || curr[1] == m - 1)
        check[1] = true;

      for (int i = 0; i < 4; i++) {
        int r = curr[0] + dr[i];
        int c = curr[1] + dc[i];
        if (r > 0 && r < n && c > 0 && c < m && heights[r][c] <= curr[2]) {
          q.push({r, c, heights[r][c]});
        }
      }
    }
    if (check[0] && check[1]) {
      res.push_back({r, c});
    }
  }
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    // implementation goes here
    if (heights.empty())
      return {};
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> res;
    vector<int> dr = {0, -1, 0, 1};
    vector<int> dc = {-1, 0, 1, 0};

    vector<bool> check(2, false);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        bfs(n, m, i, j, heights, check, res, dr, dc);
      }
    }
    return res;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> heights = {{1, 2, 2, 3, 5},
                                 {3, 2, 3, 4, 4},
                                 {2, 4, 5, 3, 1},
                                 {6, 7, 1, 4, 5},
                                 {5, 1, 1, 2, 4}};

  vector<vector<int>> result = sol.pacificAtlantic(heights);

  cout << "Cells that can flow to both oceans:\n";
  for (auto &cell : result) {
    cout << "[" << cell[0] << ", " << cell[1] << "]\n";
  }

  return 0;
}
