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

int bubbleSort(int A[], int N) {
  int flag = 1, j, count = 0;
  while ( flag ) {
    flag = 0;
    for ( j = N - 1; j > 0; j-- ) {
      if ( A[j] < A[j - 1] ) {
        swap(A[j], A[j - 1]);
        count++;
        flag = 1;
      }
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

  count = bubbleSort(A, N);
  printf("%d\n", count);

  return 0;
}

