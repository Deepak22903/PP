#include <iostream>
#include <map>
#include <vector>

int main() {
  std::vector<int> nums = {{4, 5, 1, 2, 3}}; // Example input
  std::map<int, bool> m;

  if (nums.size() < 2) {
    std::cout << "Insufficient elements in nums.\n";
    return 0;
  }

  for (int i = 0; i < nums.size() - 1; i++) { // Loop should go up to size() - 1
    if (nums[i] < nums[i + 1]) {
      m[i] = true;
    } else {
      m[i] = false;
    }
  }

  // Printing map values
  for (const auto &pair : m) {
    std::cout << "Index " << pair.first << " -> " << std::boolalpha
              << pair.second << "\n";
  }

  return 0;
}
