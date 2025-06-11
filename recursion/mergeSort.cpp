#include <iostream>
#include <vector>
using namespace std;

void mergeArr(vector<int> &arr, int start, int mid, int end) {

  vector<int> a1(arr.begin() + start, arr.begin() + mid + 1);
  vector<int> a2(arr.begin() + mid + 1, arr.begin() + end + 1);

  vector<int> res;
  int i{}, j{};
  while (i < a1.size() && j < a2.size()) {
    if (a1[i] > a2[j]) {
      res.push_back(a2[j]);
      j++;
    } else {
      res.push_back(a1[i]);
      i++;
    }
  }
  while (j < a2.size()) {
    res.push_back(a2[j]);
    j++;
  }
  while (i < a1.size()) {
    res.push_back(a1[i]);
    i++;
  }

  for (int i = 0; i < res.size(); i++) {
    arr[start + i] = res[i];
  }
}

void mergeSort(vector<int> &arr, int start, int end) {
  if (start == end)
    return;
  int mid = start + (end - start) / 2;
  mergeSort(arr, start, mid);
  mergeSort(arr, mid + 1, end);
  mergeArr(arr, start, mid, end);
}

int main(int argc, char *argv[]) {
  vector<int> arr = {3, 1, 2, 4, 1, 5, 2, 6, 4};
  mergeSort(arr, 0, arr.size() - 1);
  for (auto it : arr)
    cout << it << " ";
  cout << endl;
  return 0;
}
