#include<iostream>
using namespace std;

const int K = 10000;

void counting_sort(int A[], int B[], int n) {
  int i;
  int C[K+1] = {};

  for (i = 1; i < n+1; i++) C[A[i]]++;

  int accum = 0;
  for (i = 0; i < K+1; i++) {
    accum += C[i];
    C[i] = accum;
  }

  for (i = n; i > 0; i--) {
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
}
  

int main() {
  int i, n;
  int *A, *B;

  cin >> n;
  
  A = new int[n+1];
  B = new int[n+1];

  for (i = 1; i < n+1; i++) {
    cin >> A[i];
    B[i] = 0;
  }

  counting_sort(A, B, n);

  for (i = 1; i < n+1; i++) {
    if (i > 1) cout << " ";
    cout << B[i];
  }
  cout << endl;    

  return 0;
}

