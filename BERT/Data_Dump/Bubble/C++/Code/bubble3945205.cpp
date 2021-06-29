#include <bits/stdc++.h>
using namespace std;

void trace(int A[], int N) {
  for (int i = 0; i < N; i++) {
    if (i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main() {
  int N, A[100];
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  bool flag = 1;
  int c = 0;
  for (int i = 0; flag; i++) {
    flag = 0;
    for (int j = N-1; j >= i+1; j--) {
      if (A[j] < A[j-1]) {
        swap(A[j], A[j-1]);
        c++;
      }
      flag = 1;
    }
  }
  trace(A, N);
  cout << c << endl;
}

