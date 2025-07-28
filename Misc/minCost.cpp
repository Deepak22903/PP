#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int minCost(int n, vector<vector<int>> &edges, int k) {
    vector<int> costs;
    for (auto it : edges) {
      costs.push_back(it[2]);
    }

    if (k == 1) {
      int maxi = *max_element(costs.begin(), costs.end());
      return maxi;
    }
    // Implementation to be filled
    sort(costs.begin(), costs.end());
    int i = k;
    if (edges.size() < k)
      i = edges.size();

    return costs[costs.size() - i];
  }
};

int main() {
  Solution sol;

  int n = 4;
  vector<vector<int>> edges = {{0, 1, 5}, {1, 2, 5}, {2, 3, 5}};
  int k = 1;

  int result = sol.minCost(n, edges, k);
  cout << "Minimum cost: " << result << endl;

  return 0;
}
