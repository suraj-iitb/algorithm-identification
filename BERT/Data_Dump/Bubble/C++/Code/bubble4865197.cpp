#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, sw, A[100];

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  int swap=0;
  for (int i=0; i<N; i++) {
    for (int j=N-1; j>i; j--) {
      if (A[j] < A[j-1]) {
        int temp = A[j];
        A[j] = A[j-1];
        A[j-1] = temp;
        swap++;
      }
    }
  }

  for (int i=0; i<N; i++) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;

  cout << swap << endl;

}

