#include <algorithm>
#include <iostream>
#include <ratio>
#include <vector>
using namespace std;

class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    int res = 0;
    sort(
        points.begin(), points.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });
    int i = 0, j = 1;
    for (; j < points.size(); i++, j++) {
      if (points[j][0] <= points[i][1]) {
        while (j < points.size() && points[j][0] <= points[i][1]) {
          j++;
        }
        i = j;
        i--;
        res++;
      } else {
        res++;
      }
    }

    if (i == points.size() - 1)
      res++;
    return res;
    // Implementation goes here
  }
};

int main() {
  Solution sol;

  // Example input: balloons represented as intervals
  vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};

  int result = sol.findMinArrowShots(points);
  cout << "Minimum number of arrows required: " << result << endl;

  return 0;
}
