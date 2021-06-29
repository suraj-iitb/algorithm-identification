#include "bits/stdc++.h"
using namespace std;

void PrintArray(int*, int);
void InsertionSort(int*, int);

int main() {
  int N;
  int A[1000];

  cin >> N;
  for(int i=0; i<N; ++i) cin >> A[i];

  InsertionSort(A, N);
}

// A is an int type Array, N is the nuber of elements
void PrintArray(int* A, int N) {
  for(int i=0; i<N; ++i) {
    if(i>0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

// A is an int type Array, N is the nuber of elements
// Ascending order
void InsertionSort(int* A, int N) {
  PrintArray(A, N);
  for(int i=1; i<N; ++i) {
    int v = A[i]; // v is an element to sort
    int j = i-1;
    while(j>=0 && v < A[j]) {
      A[j+1] = A[j];
      --j;
    }
    A[j+1] = v;
    PrintArray(A, N);
  }
}

