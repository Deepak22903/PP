#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int longestMountain(vector<int> &arr) {
    // Solution goes here
    vector<vector<int>> allArrs;
    bool ASC = true;
    bool DSC = false;
    bool SRT = false;
    vector<int> list;
    for (int i = 0; i < arr.size() - 1; i++) {
      if (arr[i + 1] < arr[i]) {
        if (!DSC) {
          if (SRT) {
            ASC = false;
            DSC = true;
            SRT = false;
            list.push_back(arr[i]);
          } else {
            continue;
          }
        } else {
          list.push_back(arr[i]);
        }
      } else {
        if (ASC) {
          list.push_back(arr[i]);
          SRT = true;
        } else {
          list.push_back(arr[i]);
          allArrs.push_back(list);
          list.clear();
          ASC = true;
          DSC = false;
          SRT = false;
        }
      }
    }
    int maxSize = allArrs[0].size();
    for (auto vec : allArrs) {
      int curr = vec.size();
      maxSize = max(maxSize, curr);
    }
    return maxSize;
  }
};

int main() {
  vector<int> arr = {2, 1, 4,  7, 3,  2, 3,
                     4, 5, 12, 9, 10, 11}; // Example input with a mountain

  Solution sol;
  int result = sol.longestMountain(arr);

  cout << "Length of the longest mountain: " << result << endl;

  return 0;
}
