#include <climits>
#include <iostream>
#include <vector>

using namespace std;
vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
  vector<bool> res(candies.size());
  int max = INT_MIN;
  for (int val : candies) {
    if (val > max) {
      max = val;
    }
  }
  for (int i = 0; i < candies.size(); i++) {
    if ((candies[i] + extraCandies) > max) {
      res[i] = true;
    } else {
      res[i] = false;
    }
  }
  return res;
}
int main(int argc, char *argv[]) {
  vector<int> arr{1, 5, 2, 7};
  int extra = 5;
  vector<bool> res = kidsWithCandies(arr, extra);
  for (bool val : res) {
    cout << val << endl;
  }
  return 0;
}
