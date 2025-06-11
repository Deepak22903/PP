#include <iostream>
using namespace std;

void sum(int n, int s) {
  if (n == 0) {
    cout << s << endl;
    return;
  }
  s += n;
  sum(n - 1, s);
}

int main(int argc, char *argv[]) {
  int n{};
  cin >> n;
  sum(n, 0);
  return 0;
}
