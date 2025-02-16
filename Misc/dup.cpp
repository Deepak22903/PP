#include <iostream>
#include <unordered_map>
#include <vector>

bool check_dup(std::vector<int> nums) {
  std::unordered_map<int, bool> map;
  for (auto val : nums) {
    if (map.find(val) != map.end()) {
      return true;
    }
    map[val] = true;
  }
  return false;
}

int main() {
  std::vector<int> input = {1, 2, 3, 4};
  bool res = check_dup(input);
  if (res) {
    std::cout << "true";
  } else {
    std::cout << "false";
  }
  return 0;
}
