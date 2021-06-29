#include <bits/stdc++.h>
using namespace std;

int selectionSort (vector<int> &A, int N) {
  int sw = 0;
  int i = 0;
  for (i = 0; i < N; i++) {
    int minj = i;
    for (int j = i; j < N; j++) {
      if (A.at(j) < A.at(minj)) {
        minj = j;
      }
    }
    if (i != minj) {
      swap(A.at(i), A.at(minj));
      sw++;
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
  
  sw = selectionSort(A, N);
  
  for (int i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << A.at(i);
  }
  cout << endl;
  cout << sw << endl;
}

