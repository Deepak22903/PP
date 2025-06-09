<<<<<<< HEAD
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

=======
#include <cstddef>
#include <iostream>
#include <vector>
>>>>>>> c902853422fd82fdaa6176c92937e49e0ca66e66
using namespace std;

class Solution {
public:
  int longestMountain(vector<int> &arr) {
<<<<<<< HEAD
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
=======
    // Implementation goes here
    int maxM = 0;

    for (int i = 1; i < arr.size() - 1; i++) {
      if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
        int left = i - 1;
        int right = i + 1;

        while (left > 0 && arr[left - 1] < arr[left]) {
          left--;
        }
        while (right < arr.size() - 1 && arr[right] > arr[right + 1]) {
          right++;
        }
        int currMaxM = right - left + 1;
        maxM = max(maxM, currMaxM);
        i = right;
      }
    }
    return maxM;
>>>>>>> c902853422fd82fdaa6176c92937e49e0ca66e66
  }
};

int main() {
<<<<<<< HEAD
  vector<int> arr = {2, 1, 4,  7, 3,  2, 3,
                     4, 5, 12, 9, 10, 11}; // Example input with a mountain

  Solution sol;
  int result = sol.longestMountain(arr);

  cout << "Length of the longest mountain: " << result << endl;

=======
  Solution sol;
  vector<int> arr = {875, 884, 239, 731, 723, 685};
  int result = sol.longestMountain(arr);
  cout << "Longest mountain length: " << result << endl;
>>>>>>> c902853422fd82fdaa6176c92937e49e0ca66e66
  return 0;
}
