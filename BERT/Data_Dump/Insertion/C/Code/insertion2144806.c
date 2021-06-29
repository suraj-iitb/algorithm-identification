#include<stdio.h>

static const int N = 1000;

void trace(int A[], int n){
  int i;
  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(){
  int n, i, j;
  int A[N+1];
  scanf("%d", &n);

  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);

  trace(A, n);

  for ( i = 2; i < n+1 ; i++) {
    int key = A[i];
    int j = i-1;
    while (j >= 1 && A[j] > key) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    trace(A, n);
     /* code */
  }

  return 0;
}
