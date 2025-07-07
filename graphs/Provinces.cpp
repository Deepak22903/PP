#include <iostream>
#include <vector>

class Solution {
public:
  void dfs(std::vector<std::vector<int>> &isConnected, int curr,
           std::vector<int> &vis) {
    vis[curr] = 1;
    for (int i = 0; i < isConnected[curr].size(); i++) {
      if (isConnected[curr][i] == 1 && vis[i] == 0) {
        dfs(isConnected, i, vis);
      }
    }
  }
  int findCircleNum(std::vector<std::vector<int>> &isConnected) {
    int res = 0;
    std::vector<int> vis(isConnected.size(), 0);
    for (int i = 0; i < vis.size(); i++) {
      if (vis[i] == 0) {
        dfs(isConnected, i, vis);
        res++;
      }
    }
    return res;
  }
};

int main() {
  Solution sol;

  // Test case 1
  std::vector<std::vector<int>> isConnected1 = {
      {1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  std::cout << "Input: [[1,1,0],[1,1,0],[0,0,1]]" << std::endl;
  std::cout << "Expected: 2" << std::endl;
  std::cout << "Actual: " << sol.findCircleNum(isConnected1) << std::endl;

  std::cout << std::endl;

  // Test case 2
  std::vector<std::vector<int>> isConnected2 = {
      {1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  std::cout << "Input: [[1,0,0],[0,1,0],[0,0,1]]" << std::endl;
  std::cout << "Expected: 3" << std::endl;
  std::cout << "Actual: " << sol.findCircleNum(isConnected2) << std::endl;

  return 0;
}
