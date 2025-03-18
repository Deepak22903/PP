#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> height) {
  int i = 0;
  int j = height.size() - 1;
  int max = (height[i] > height[j] ? height[j] : height[i]) * j;
  while (i < j) {
    height[i] > height[j] ? j-- : i++;
    if (((height[i] > height[j] ? height[j] : height[i]) * (j - i)) > max) {
      max = (height[i] > height[j] ? height[j] : height[i]) * (j - i);
    }
  }
  return max;
}

int main(int argc, char *argv[]) {
  vector<int> arr{1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << maxArea(arr) << endl;
  return 0;
}
