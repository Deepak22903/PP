#include <iostream>
#include <vector>
using namespace std;

void rev(vector<int> &arr, int l, int r) {
  if (l >= r)
    return;
  swap(arr[l], arr[r]);
  rev(arr, l + 1, r - 1);
}

int main(int argc, char *argv[]) {
  vector<int> arr = {1, 2, 3, 4, 5};
  cout << "Before reverse : \n";
  for (int val : arr) {
    cout << val << " ";
  }

  rev(arr, 0, arr.size() - 1);

  cout << "\n After reverse : \n";
  for (int val : arr) {
    cout << val << " ";
  }

  return 0;
}
