#include<stdio.h>

void trace(int A[], int N) {
  int i;
  for ( i = 0; i < N; i++ ) {
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void bubbleSort(int A[], int N){
  int flag, i, j, k, m;
  flag = 1;
  i = 0;
  m = 0;
  while (flag) {
    flag = 0;
    for ( j = N-1; j > i; j-- ){
      if ( A[j] < A[j - 1]){
	k = A[j];
	A[j] = A[j - 1];
	A[j - 1] = k;
	flag = 1;
	m++;
      }
    }
    i++;
  }
  trace(A, N);
  printf("%d\n", m);
}

int main(){
  int N, i, j;
  int A[100];

  scanf("%d", &N);
  for ( i = 0; i < N; i++ ) scanf("%d", &A[i]);

  bubbleSort(A, N);

  return 0;
}

