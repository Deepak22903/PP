#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  void bfs(int n, int m, int r, int c, vector<vector<int>> &heights,
           vector<bool> &check, vector<vector<int>> &res, vector<int> &dr,
           vector<int> &dc) {

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;

    q.push({r, c});
    visited[r][c] = true;

    while (!q.empty()) {
      auto [cr, cc] = q.front();
      q.pop();

      if (cc == 0 || cr == 0)
        check[0] = true; // Pacific
      if (cr == n - 1 || cc == m - 1)
        check[1] = true; // Atlantic

      for (int i = 0; i < 4; i++) {
        int nr = cr + dr[i];
        int nc = cc + dc[i];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] &&
            heights[nr][nc] <= heights[cr][cc]) {
          visited[nr][nc] = true;
          q.push({nr, nc});
        }
      }
    }

    if (check[0] && check[1]) {
      res.push_back({r, c}); // the original cell
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

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        vector<bool> check(2, false);
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
