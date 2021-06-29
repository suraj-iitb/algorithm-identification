#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

void PrintArray(int*, int);
int BubbleSort(int*, int);

int main() {
  int N;
  int A[100];

  cin >> N;
  for(int i=0; i<N; ++i) cin >> A[i];

  printf("%d\n", BubbleSort(A, N));

}

void PrintArray(int *A, int N) {
  for(int i=0; i<N; ++i) {
    if(i>0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

// Return the sum of changing
int BubbleSort(int *A, int N) {
  int flg = 1;
  int chnum = 0;

  while(flg) {
    flg = 0;
    for(int i=N-1; i>0; --i) {
      if(A[i] < A[i-1]) {
        int tmp = A[i];
        A[i] = A[i-1];
        A[i-1] = tmp;
        ++chnum;
        flg = 1;
      }
    }
  }
  PrintArray(A, N);
  return chnum;
}

