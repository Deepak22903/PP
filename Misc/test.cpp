#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {

  vector<string> arr;
  arr.push_back("a");
  arr.insert(arr.begin() + 1, to_string(2));
  arr.insert(arr.begin() + 2, "b");
  for (string val : arr) {
    cout << val << " ";
  }
}
