#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int numberOfPermutations(int n, vector<vector<int>> &requirements) {
    // Solution goes here
    int res = 0;
    map<vector<int>, bool> mapPerm;
    vector<int> nums;
    sort(requirements.begin(), requirements.end());
    reverse(requirements.begin(), requirements.end());
    for (int i = 0; i <= n - 1; i++) {
      nums.push_back(i);
    }
    do {
      mapPerm[nums] = false;
    } while (next_permutation(nums.begin(), nums.end()));

    for (int i = 0; i < requirements.size(); i++) {
      int end = requirements[i][0];
      int maxInversion = requirements[i][1];
      for (auto it = mapPerm.begin(); it != mapPerm.end(); ++it) {
        if (i == 0 || it->second == true) {
          vector<int> arr = it->first;
          int lastIndex = end;
          int Inversion = 0;
          for (int m = 0; m <= end; m++) {
            for (int n = m + 1; n <= end; n++) {
              if (arr[m] > arr[n])
                Inversion++;
              if (Inversion > maxInversion)
                break;
            }
            if (Inversion > maxInversion) {
              it->second = false;
              break;
            }
          }
          if (Inversion < maxInversion) {
            it->second = false;
          }
          if (Inversion == maxInversion)
            it->second = true;
        }
      }
    }
    for (auto it = mapPerm.begin(); it != mapPerm.end(); ++it) {
      if (it->second == true)
        res++;
    }

    return res;
  }
};

int main() {
  int n = 2;
  vector<vector<int>> requirements = {{0, 0}, // 2 before 3
                                      {1, 0}};

  Solution sol;
  int result = sol.numberOfPermutations(n, requirements);

  cout << "Number of valid permutations: " << result << endl;

  return 0;
}
