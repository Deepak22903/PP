#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  int mod = 1e9 + 7;
  int countTrapezoids(vector<vector<int>> &points) {

    unordered_map<int, int> mp;
    for (int i = 0; i < points.size(); i++) {
      mp[points[i][1]]++;
    }
    vector<long long> pairs;
    for (auto it : mp) {
      if (it.second == 2) {
        pairs.push_back(1);
      } else if (it.second > 2) {
        pairs.push_back((1LL * (it.second) * (it.second - 1) / 2) % mod);
      }
    }
    long long res = 0;
    for (int i = 0; i < pairs.size(); i++) {
      for (int j = i + 1; j < pairs.size(); j++) {
        res += pairs[i] * pairs[j];
      }
    }
    // Implementation will go here
    return res % mod;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> points = {{-17, -75}, {49, -75},  {-81, -75},
                                {-75, -65}, {-63, -65}, {68, -75}};

  int result = sol.countTrapezoids(points);
  cout << "Number of trapezoids: " << result << endl;

  return 0;
}
