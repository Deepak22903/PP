#include <iostream>
#include <vector>
using namespace std;

int setPivot(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int i = low;
  int j = high;
  while (i <= j) {
    while (i <= high && arr[i] <= pivot)
      i++;
    while (j >= low && arr[j] > pivot)
      j--;
    if (i < j)
      swap(arr[i], arr[j]);
  }
  swap(arr[low], arr[j]);
  return j;
}

void quickSort(vector<int> &arr, int low, int high) {
  if (low >= high)
    return;
  int pivotIndex = setPivot(arr, low, high);
  quickSort(arr, low, pivotIndex - 1);
  quickSort(arr, pivotIndex + 1, high);
}

int main(int argc, char *argv[]) {
  vector<int> arr = {3, 2, 5, 1, 4};
  quickSort(arr, 0, arr.size() - 1);
  for (auto it : arr)
    cout << it << " ";

  return 0;
}
