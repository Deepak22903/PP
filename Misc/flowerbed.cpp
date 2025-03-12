
#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n) {
  if (n == 0) {
    return true;
  }
  if (flowerbed.size() == 1) {
    if (flowerbed[0] == 0) {
      n--;
      if (n == 0)
        return true;
    }
  }

  for (int i = 0; i < flowerbed.size(); i++) {
    if (i == 0 && i < flowerbed.size() - 1 && flowerbed[i] == 0 &&
        flowerbed[i + 1] == 0) {
      flowerbed[i] = 1;
      n--;
      if (n == 0)
        return true;
    } else if (i > 0 && i < flowerbed.size() - 1 && flowerbed[i - 1] == 0 &&
               flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
      flowerbed[i] = 1;
      n--;
      if (n == 0)
        return true;
    }

    else if (i == flowerbed.size() - 1 &&
             flowerbed[flowerbed.size() - 1] == 0 &&
             flowerbed[flowerbed.size() - 2] == 0) {
      n--;
      if (n == 0)
        return true;
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  vector<int> arr{0, 0, 0, 0};
  bool res = canPlaceFlowers(arr, 3);
  cout << res << endl;
  return 0;
}
