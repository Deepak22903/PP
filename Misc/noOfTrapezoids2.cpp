
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isParallel(pair<int, int> a, pair<int, int> b, pair<int, int> c,
                  pair<int, int> d) {
    long long dy1 = b.second - a.second;
    long long dx1 = b.first - a.first;
    long long dy2 = d.second - c.second;
    long long dx2 = d.first - c.first;
    return dy1 * dx2 ==
           dy2 * dx1; // check slope equality via cross multiplication
  }
  int countTrapezoids(vector<vector<int>> &points) {
    int n = points.size();

    set<vector<int>> seen;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          for (int l = k + 1; l < n; l++) {
            bool trapezoid = isParallel({points[i][0], points[i][1]},
                                        {points[j][0], points[j][1]},
                                        {points[k][0], points[k][1]},
                                        {points[l][0], points[l][1]}) ||
                             isParallel({points[i][0], points[i][1]},
                                        {points[k][0], points[k][1]},
                                        {points[j][0], points[j][1]},
                                        {points[l][0], points[l][1]}) ||
                             isParallel({points[i][0], points[i][1]},
                                        {points[l][0], points[l][1]},
                                        {points[j][0], points[j][1]},
                                        {points[k][0], points[k][1]});

            if (trapezoid) {
              vector<int> quad = {i, j, k, l};
              sort(quad.begin(), quad.end());
              seen.insert(quad);
            }
          }
        }
      }
    }
    return seen.size();
  }
};

int main() {
  Solution sol;
  vector<vector<int>> points = {{71, -89},  {-75, -89}, {-9, 11}, {-24, -89},
                                {-51, -89}, {-77, -89}, {42, 11}};
  int result = sol.countTrapezoids(points);
  cout << "Number of trapezoids: " << result << endl;
  return 0;
}
