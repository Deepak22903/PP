#include <iostream>
#include <vector>

using namespace std;
int largestAltitude(vector<int> &gain) {
  int res = 0;
  int max = 0;
  for (int i = 0; i < gain.size(); i++) {
    res += gain[i];
    if (res > max) {
      max = res;
    }
  }
  return max;
}
int main(int argc, char *argv[]) {
  vector<int> arr{52, -91, 72};
  cout << largestAltitude(arr) << endl;

  return 0;
}
