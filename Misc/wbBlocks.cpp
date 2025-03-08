#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// int wbBlocks(vector<char> blocks, int start, int end) {
//   int count{};
//   for (int i = start; i <= end; i++) {
//     if (blocks[i] == 'W')
//       count++;
//   }
//   cout << "itr( " << start << "-" << end << "): " << count << endl;
//   return count;
// }
//
// int main(int argc, char *argv[]) {
//   vector<char> blocks{'W', 'B', 'B', 'W', 'B', 'W', 'W', 'W', 'B', 'W', 'B'};
//   // vector<char> blocks{'W', 'B', 'B', 'W'};
//   int k{7};
//   int i{0};
//   int n{k - 1};
//   int min{INT_MAX};
//   while (n < blocks.size()) {
//     int res = wbBlocks(blocks, i, n);
//     if (res < min)
//       min = res;
//     i++;
//     n++;
//   }
//   cout << min << endl;
//
//   return 0;
// }

int main(int argc, char *argv[]) {
  string blocks{"WBBW"};
  int k{2};
  int i{0};
  int j{0};
  int W{};
  while (j < blocks.size()) {
    if (blocks[j] == 'W')
      W++;
    j++;
  }

  return 0;
}
