#include <iostream>
#include <numeric>
using namespace std;

int main(int argc, char *argv[]) {
  auto res = std::gcd(2, 10);
  cout << res << endl;
  return 0;
}
