#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// string get_date() {
//   auto now = chrono::system_clock::now();
//   time_t now_time = chrono::system_clock::to_time_t(now);
//   tm local_time = *localtime(&now_time);
//   ostringstream oss;
//   oss << put_time(&local_time, "%d %B %Y");
//   string date = oss.str();
//   return date;
// }

// string my_reverse(string s) {
//   string res{};
//   stack<char> ch;
//   for (int i = 0; i < s.size(); i++) {
//     ch.push(s[i]);
//   }
//   while (!ch.empty()) {
//     res = res + ch.top();
//     ch.pop();
//   }
//   return res;
// }
//
// int main(int argc, char *argv[]) {
//
//   string s{"dick n balls"};
//   string res = my_reverse(s);
//   cout << "reversed string : " << res << "\n";
//
//   return 0;
// }
//
//
//

int main(int argc, char *argv[]) {
  vector<int> arr{3, 2, 2, 3};
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == 2) {
      arr.erase(arr.begin() + i);
      i--;
    }
  }
  for (int val : arr) {
    cout << val << endl;
  }
  return 0;
}
