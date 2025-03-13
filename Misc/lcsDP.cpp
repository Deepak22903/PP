#include <iostream>

using namespace std;

string lcs(string A, string B) {
  int Alen = A.size();
  int Blen = B.size();
  char arr[Alen + 1][Blen + 1];
  for (int i = 0; i <= Alen; i++) {
    for (int j = 0; j <= Blen; j++) {
      arr[i][j] = '1'; // Set all elements to 0
    }
  }
  for (int i = 0; i < max(Alen, Blen); i++) {
    if (i < Alen)
      arr[i][0] = '0';
    if (i < Blen)
      arr[0][i] = '0';
  }
  cout << "2D Array:\n";
  for (int i = 0; i < Alen; i++) {
    for (int j = 0; j < Blen; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  // for(int i = 0; i < A.size(); i++){
  //   for(int j =  0; j < B.size();j++){
  //     if(A[i]==B[j]){
  //
  //     }
  //   }
  // }
  return "";
}

int main(int argc, char *argv[]) {
  string s1 = "stone";
  string s2 = "longest";
  string res = lcs(s1, s2);

  return 0;
}
