#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void qSort(vector<int> &arr, int low, int high) {
  if (low >= high)
    return;
  int pivot = arr[low];
  int i = low + 1;
  int j = high;
  while (i <= j) {
    while (i <= high && arr[i] <= pivot)
      i++;
    while (j > low && arr[j] > pivot)
      j--;
    if (i < j)
      swap(arr[i], arr[j]);
  }
  swap(arr[low], arr[j]);
  qSort(arr, low, j - 1);
  qSort(arr, j + 1, high);
}

int main(int argc, char *argv[]) {
  vector<int> arr = {3, 1, 2, 4, 1, 5, 2, 6, 4};
  qSort(arr, 0, arr.size() - 1);
  for (auto it : arr) {
    cout << it << " ";
  }
  return 0;
}
