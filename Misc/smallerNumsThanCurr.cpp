#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
    // Solution goes here
    map<int, int> nmap;
    vector<int> temp(nums);
    sort(nums.begin(), nums.end());
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      nmap[nums[i]] = count;
      while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
        i++;
        count++;
      }
      count++;
    }

    for (int i = 0; i < temp.size(); i++) {
      auto it = nmap.find(temp[i]);
      if (it != nmap.end()) {
        temp[i] = it->second;
      }
    }
    return temp;
  }
};

int main() {
  vector<int> nums = {8, 1, 2, 2, 3}; // Example input

  Solution sol;
  vector<int> result = sol.smallerNumbersThanCurrent(nums);

  // Output the result
  cout << "Result: ";
  for (int num : result) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
