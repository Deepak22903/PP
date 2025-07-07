#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

void bfs(vector<int> graph[], vector<int> &vis) {
  queue<int> q;
  q.push(0);
  vis[0] = 1;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    cout << curr << endl;
    for (auto val : graph[curr]) {
      if (vis[val] == 1)
        continue;
      q.push(val);
      vis[val] = 1;
    }
  }
}
int main(int argc, char *argv[]) {
  vector<int> graph[10] = {{1, 2, 4}, {0, 3, 5}, {0, 3, 6}, {1, 2, 7}, {0, 8},
                           {1, 9},    {2, 9},    {3},       {4},       {5, 6}};
  vector<int> vis(10, 0);
  bfs(graph, vis);

  return 0;
}
