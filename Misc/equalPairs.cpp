#include <iostream>
#include <vector>
using namespace std;

int equalPairs(vector<vector<int>> &grid) {
  int res{};
  for (int i = 0; i < grid.size(); i++) {
    vector<int> temp;
    for (int j = 0; j < grid.size(); j++) {
      temp.push_back(grid[j][i]);
    }

    for (int k = 0; k < grid.size(); k++) {
      if (grid[k] == temp)
        res++;
    }
  }
  return res;
}

int main(int argc, char *argv[]) {
  vector<vector<int>> grid{
      {3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
  cout << equalPairs(grid) << endl;
  return 0;
}
