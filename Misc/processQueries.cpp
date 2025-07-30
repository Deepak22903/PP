#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  void dfs(vector<vector<int>> &adj, int curr,
           priority_queue<int, vector<int>, greater<int>> &minHeap,
           vector<bool> &visited) {
    visited[curr] = true;
    minHeap.push(curr);
    for (int i = 0; i < adj[curr].size(); i++) {
      if (!visited[adj[curr][i]])
        dfs(adj, adj[curr][i], minHeap, visited);
    }
  }
  vector<int> processQueries(int c, vector<vector<int>> &connections,
                             vector<vector<int>> &queries) {
    // your implementation here

    vector<int> res;
    vector<vector<int>> adj(c + 1);
    vector<bool> isUp(c + 1, true);
    adj[0] = {};
    for (int i = 0; i < connections.size(); i++) {
      adj[connections[i][0]].push_back(connections[i][1]);
      adj[connections[i][1]].push_back(connections[i][0]);
    }
    for (int i = 0; i < queries.size(); i++) {
      if (queries[i][0] == 1 && isUp[queries[i][1]]) {
        res.push_back(queries[i][1]);
      } else if (queries[i][0] == 2) {
        isUp[queries[i][1]] = false;
      } else if (queries[i][0] == 1 && !isUp[queries[i][1]]) {
        vector<bool> visited(c + 1, false);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        dfs(adj, queries[i][1], minHeap, visited);
        while (!minHeap.empty()) {
          if (!isUp[minHeap.top()])
            minHeap.pop();
          else
            break;
        }
        if (!minHeap.empty())
          res.push_back(minHeap.top());
        else
          res.push_back(-1);
      }
    }
    return res; // placeholder
  }
};

int main() {
  Solution sol;

  // Test Case 1
  int c1 = 5;
  vector<vector<int>> connections1 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
  vector<vector<int>> queries1 = {{1, 3}, {2, 1}, {1, 1}, {2, 2}, {1, 2}};
  vector<int> result1 = sol.processQueries(c1, connections1, queries1);
  cout << "Test Case 1 Output:\n";
  for (int val : result1)
    cout << val << " ";
  cout << "\nExpected: 3 2 3\n\n";

  // Test Case 2
  int c2 = 3;
  vector<vector<int>> connections2 = {}; // no connections
  vector<vector<int>> queries2 = {{1, 1}, {2, 1}, {1, 1}};
  vector<int> result2 = sol.processQueries(c2, connections2, queries2);
  cout << "Test Case 2 Output:\n";
  for (int val : result2)
    cout << val << " ";
  cout << "\nExpected: 1 -1\n";

  return 0;
}
