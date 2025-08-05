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
    int waterMinDur = INT_MAX;
    int landMinDur = INT_MAX;

    for (int i = 0; i < waterStartTime.size(); i++) {
      waterMinDur = min(waterMinDur, waterStartTime[i] + waterDuration[i]);
    }
    for (int i = 0; i < landStartTime.size(); i++) {
      landMinDur = min(landMinDur, landStartTime[i] + landDuration[i]);
    }

    for (int i = 0; i < landStartTime.size(); ++i) {
      for (int j = 0; j < waterStartTime.size(); ++j) {
        // Option 1: land first, then water
        int total1 = waterDuration[j] + max(waterStartTime[j], landMinDur);

        // Option 2: water first, then land
        int total2 = landDuration[i] + max(landStartTime[i], waterMinDur);

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
