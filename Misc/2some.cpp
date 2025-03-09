#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
  vector<int> numbers{1, 2, 3, 4};
  int target{6};
  // map<int, int> map;
  // for (int i = 0; i < arr.size(); i++) {
  //   int k = target - arr[i];
  //   if (map.find(k) != map.end()) {
  //     cout << map[k] << endl;
  //     cout << i << endl;
  //     break;
  //   }
  //   map[arr[i]] = i;
  // }
  //
  // 2 some II
  int i{};
  int j(numbers.size() - 1);
  while (i != j) {
    if ((numbers[i] + numbers[j]) > target) {
      j--;
    } else if ((numbers[i] + numbers[j]) < target) {
      i++;
    } else if ((numbers[i] + numbers[j]) == target) {
      cout << i << endl << j << endl;
      break;
    }
  }
  return 0;
}
