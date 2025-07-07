#include <bits/stdc++.h>
#include <vector>
using namespace std;
void dfs(int curr, vector<int> graph[], vector<int> &vis) {
  vis[curr] = 1;
  cout << curr << endl;
  for (int i = 0; i < graph[curr].size(); i++) {
    if (vis[graph[curr][i]] != 1) {
      dfs(graph[curr][i], graph, vis);
    }
  }
}
int main(int argc, char *argv[]) {
  vector<int> graph[10] = {{1, 2, 4}, {0, 3, 5}, {0, 3, 6}, {1, 2, 7}, {0, 8},
                           {1, 9},    {2, 9},    {3},       {4},       {5, 6}};
  vector<int> vis(10, 0);
  dfs(0, graph, vis);

  return 0;
}
