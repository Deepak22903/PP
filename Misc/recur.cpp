#include <iostream>
#include <vector>
int sum(std::vector<int> arr) {
  if (arr.size() == 1)
    return arr[0];
  int mid = arr.size() / 2;
  std::vector<int> first(arr.begin(), arr.begin() + mid);
  std::vector<int> second(arr.begin() + mid, arr.end());
  int one = sum(first);
  int two = sum(second);
  return one + two;
}

int main() {
  std::vector<int> arr = {1, 2, 3, 4};
  int res = sum(arr);
  std::cout << res << std::endl;
}
