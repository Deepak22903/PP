#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int start, int mid, int end) {}

void mergeSort(vector<int> &arr, int i, int j) {
  if (i < j) {
    int mid = i + (j - i) / 2;

    mergeSort(arr, i, mid);
    mergeSort(arr, mid + 1, j);

    merge(arr, i, mid, j);
  }
}

int main() {
  vector<int> arr = {1, 5, 3, 4, 2};
  mergeSort(arr, 0, arr.size() - 1);
  for (int val : arr) {
    cout << val << " ";
  }
  cout << endl;
}
