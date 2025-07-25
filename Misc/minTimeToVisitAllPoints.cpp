#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>> &points) {
    int res = 0;
    for (int i = 1; i < points.size(); i++) {
      res += max(abs(points[i][0] - points[i - 1][0]),
                 abs(points[i][1] - points[i - 1][1]));
    }
    return res;
  }
};

int main() {
  Solution s;

  vector<vector<int>> p = {{1, 1}, {3, 4}, {-1, 0}};
  cout << s.minTimeToVisitAllPoints(p) << endl;
}
