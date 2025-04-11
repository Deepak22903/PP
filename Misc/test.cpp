#include <iostream>
#include <vector>

int main() {
  std::vector<std::vector<int>> array = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  // Removing the second element of the second row
  array[1].erase(array[1].begin() + 1);
  for (const auto &floor : array) {
    for (int unit : floor) {
      std::cout << unit << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
