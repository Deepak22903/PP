#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  // std::string s;
  // std::cout << "Enter a line :";
  // std::getline(std::cin, s);
  // std::cout << "You typed: " << s << "\n";
  // std::vector<double> arr;
  // double i;
  // while (std::cin >> i)
  //   arr.push_back(i);
  // for (double j : arr)
  //   std::cout << j << std::endl;

  // int s_to_int = stoi(s);
  // string i_to_s = to_string(i);
  // cout << "int : " << s_to_int << " string : " << i_to_s << endl;
  // string s = "999999999999999999999999999999999999999999999999999999999999";
  // int i = 500000000;
  // char ch = 'A';
  // unsigned short si = 65535;
  // long li = 999;
  // double di = 999;
  // float fi = 999;
  // cout << sizeof(s) * 8 << endl;
  // cout << sizeof(i) * 8 << endl;
  // cout << sizeof(ch) * 8 << endl;
  // cout << sizeof(si) * 8 << endl;
  // cout << sizeof(li) * 8 << endl;
  // cout << sizeof(di) * 8 << endl;
  // cout << sizeof(fi) * 8 << endl;

  string input = "3[a2[c]]";
  if (input[2] == 'a')
    cout << "true" << endl;
  cout << input[2] << endl;
}
