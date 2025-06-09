#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int longestMountain(vector<int> &arr) {
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
  }
};

int main() {
  Solution sol;
  vector<int> arr = {875, 884, 239, 731, 723, 685};
  int result = sol.longestMountain(arr);
  cout << "Longest mountain length: " << result << endl;
  return 0;
}
