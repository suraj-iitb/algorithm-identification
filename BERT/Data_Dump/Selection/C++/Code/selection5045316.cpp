#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

void PrintArray(int*, int);
int SelectionSort(int*, int);

int main() {
  int N;
  int A[100];

  cin >> N;
  for(int i=0; i<N; ++i) cin >> A[i];

  printf("%d\n", SelectionSort(A, N));
}

// A is an int type Array, N is the nuber of elements
void PrintArray(int* A, int N) {
  for(int i=0; i<N; ++i) {
    if(i>0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

// Return the sum of changing
int SelectionSort(int *A, int N) {
  int chnum = 0;
  for(int i=0; i<N; ++i) {
    int min = i;
    for(int j=i+1; j<N; ++j) {
      if(A[j] < A[min]) {
        min = j;
      }
    }
    if(min != i) {
      int tmp = A[i];
      A[i] = A[min];
      A[min] = tmp;
      ++chnum;
    }
  }
  PrintArray(A, N);
  return chnum;
}

