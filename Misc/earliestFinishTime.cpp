#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration,
                         vector<int> &waterStartTime,
                         vector<int> &waterDuration) {

    int res = INT_MAX;

    for (int i = 0; i < landStartTime.size(); ++i) {
      for (int j = 0; j < waterStartTime.size(); ++j) {
        // Option 1: land first, then water
        int landEnd = landStartTime[i] + landDuration[i];
        int startWater = max(landEnd, waterStartTime[j]);
        int total1 = startWater + waterDuration[j];

        // Option 2: water first, then land
        int waterEnd = waterStartTime[j] + waterDuration[j];
        int startLand = max(waterEnd, landStartTime[i]);
        int total2 = startLand + landDuration[i];

        res = min(res, min(total1, total2));
      }
    }
    return res;
  }
};

int main() {
  Solution sol;

  vector<int> landStartTime = {2, 8};
  vector<int> landDuration = {4, 1};
  vector<int> waterStartTime = {6}; // Placeholder for complete input
  vector<int> waterDuration = {3};  // Placeholder for complete input

  int result = sol.earliestFinishTime(landStartTime, landDuration,
                                      waterStartTime, waterDuration);
  cout << "Earliest Finish Time: " << result << endl;

  return 0;
}
