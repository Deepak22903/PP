#include <climits>
#include <iostream>
#include <vector>
using namespace std;

bool increasingTriplet(vector<int> &nums) {
  // If the array has fewer than 3 elements, return false
  if (nums.size() < 3) {
    return false;
  }

  // Track the smallest and second smallest elements seen so far
  int first = INT_MAX;  // smallest element
  int second = INT_MAX; // second smallest element

  for (int num : nums) {
    // If current number is smaller than the smallest, update first
    if (num <= first) {
      first = num;
    }
    // If current number is larger than first but smaller than second, update
    // second
    else if (num <= second) {
      second = num;
    }
    // If current number is larger than both first and second, we found our
    // triplet
    else {
      return true;
    }
  }

  return false;
}

int main(int argc, char *argv[]) {
  // Test with the example array
  vector<int> arr{1, 5, 0, 4, 1, 3};
  bool res = increasingTriplet(arr);
  cout << "Result: " << (res ? "true" : "false") << endl;

  return 0;
}
