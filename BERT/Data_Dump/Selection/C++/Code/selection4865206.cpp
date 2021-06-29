#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sw, A[100];

  // inputs
  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  // selection sort
  int mini;
  int swap = 0;
  for (int i=0; i<N; i++) {
    mini = i;
    for (int j=i; j<N; j++) {
      if (A[j] < A[mini]) {
        mini = j;
      }
    }
    if (i != mini) {
      int temp = A[i];
      A[i] = A[mini];
      A[mini] = temp;
      swap++;
    }
  }

  // outputs
  for (int i=0; i<N; i++) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;

  cout << swap << endl;

}

