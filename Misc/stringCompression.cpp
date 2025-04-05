#include <iostream>
#include <string>
#include <vector>
using namespace std;

int compress(vector<char> &chars) {
  int len = chars.size();
  vector<string> res;
  int curr = 0;
  for (int i = 0; i < len; i++) {
    char ch = chars[i];
    int count{1};
    while ((i + 1) < len && chars[i + 1] == ch) {
      count++;
      i++;
    }
    if (count == 1) {
      chars[curr] = ch;
      curr++;
    } else if (count < 9) {
      chars[curr] = ch;
      curr++;
      for (const char c : to_string(count)) {
        chars[curr] = c;
      }
      curr++;
    } else {
      chars[curr] = ch;
      curr++;
      for (const char c : to_string(count)) {
        chars[curr] = c;
        curr++;
      }
    }
  }
  chars.erase(chars.begin() + curr, chars.end());
  return curr;
}

int main(int argc, char *argv[]) {
  vector<char> arr{'a', 'b', 'b', 'b', 'b', 'b', 'b',
                   'b', 'b', 'b', 'b', 'b', 'b'};
  int res = compress(arr);
  cout << res << endl;
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  return 0;
}
