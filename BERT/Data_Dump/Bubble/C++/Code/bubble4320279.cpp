#include <bits/stdc++.h>
using namespace std;

int bubbleSort (vector<int> &A, int N) {
  int sw = 0;
  bool flag = 1;
  int i = 0;
//  while (flag) {
    for (i = 0; flag; i++) {
    flag = 0;
    for (int j = N - 1; j >= i + 1; j--) {
      if (A.at(j) < A.at(j - 1)) {
        swap(A.at(j), A.at(j - 1));
        flag = 1;
        sw++;
      }
    }
  }
  return sw;
}
  
int main() {
  int N, sw;
  cin >> N;
  
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }  
  
  sw = bubbleSort(A, N);
  
  for (int i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << A.at(i);
  }
  cout << endl;
  cout << sw << endl;
}

