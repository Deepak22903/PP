#include <iostream>
#include <vector>

using namespace std;
double findMaxAverage(vector<int> &nums, int k) {
  int i = 0;
  int j = 0;
  double sum = 0;
  while (i < k) {
    sum = sum + nums[i];
    i++;
  }
  double maxAvg = sum / k;
  while (i < nums.size()) {
    sum = sum - nums[j];
    cout << "sum = sum - nums[j]: " << sum << endl;
    sum = sum + nums[i];
    cout << "sum = sum + nums[i]: " << sum << endl;
    cout << "Avg: " << sum / k << endl;
    if ((sum / k) > maxAvg) {
      maxAvg = (sum / k);
    }
    i++;
    j++;
  }
  return maxAvg;
}
int main(int argc, char *argv[]) {
  vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8};
  int k = 3;
  double res = findMaxAverage(nums, k);
  cout << res << endl;

  return 0;
}
