#include <iostream>
using namespace std;
// #include <iostream>
// #include <thread>
// #include <vector>
//
// int main() {
//   // std::vector<int> arr{1, 2, 3, 4, 5, 6};
//   // for (const auto i : arr)
//   //   std::cout << i << "\n";
//   // std::cout << "Hello world!";
//   // long a;
//   // while (1) {
//   //   std::cout << a << "\n";
//   // }
//
//   return 0;
// }
#include <codecvt>
#include <iostream>
#include <ostream>
// The program prints the tree values that you provide to it
int main() {
  // An integer can only hold non-fractional values.
  // Initializing an int with fractional value 4.5 requires the compiler to
  // convert 4.5 to a value an int can hold. Such a conversion is a narrowing
  // conversion, since the fractional part of the value will be lost.

  // int w1{}; // compile error: list-init does not allow narrowing conversion
  // std::cout << w1;
  // int i = 65;
  //
  // int *ptr = &i;
  // char *chptr = reinterpret_cast<char *>(ptr);
  // std::cout << *chptr << '\n';

  int a{};
  char b{};
  int c{};
  std::cin >> a >> b >> c;
  std::cout << "This is int : " << a << "\n This is char:" << b
            << "\nThis is int:" << c << std::endl;
  // if (std::cin.eof())
  //   std::cout << "hii";
  // std::cin >> a;
  // std::cout << a;
  // return 0;
  // int a{}, b{}, c{};
  // cout << "Enter three numbers: ";
  // cin >> a >> b >> c;
  // cout << "You entered " << a << ", " << b << ", and " << c << "\n";
}
