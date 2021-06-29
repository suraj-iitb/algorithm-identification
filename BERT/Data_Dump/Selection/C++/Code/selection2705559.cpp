#include<stdio.h>
#include<algorithm>
using namespace std;

void trace(int A[], int N) {
  int i;
  for ( i = 0; i < N; i++ ) {
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int selectionSort(int A[], int N) {
  int i, j, minj, count = 0;
  for (i=0;i<N;i++) {
    minj = i;
    for (j=i;j<N;j++) {
      if (A[j] < A[minj]) {
        minj=j;
      }
    }
    if (minj > i) {
      swap(A[i],A[minj]);
      count++;
    }
  }
  trace(A, N);
  return count;
}

int main() {
	int N, i, count;
  int A[100];

  scanf("%d", &N);
  for ( i = 0; i < N; i++ ) scanf("%d", &A[i]);

  count = selectionSort(A, N);
  printf("%d\n", count);

  return 0;
}

