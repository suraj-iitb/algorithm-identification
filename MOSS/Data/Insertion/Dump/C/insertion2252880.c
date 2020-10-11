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
  int n, i, j, k;
  int A[N+1];
  scanf("%d", &n);
  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);
  trace(A, n);

  for(j = 2;j <= n;j++){
    k = A[j];
    i = j -1;
    while(i > 0 && A[i] > k){
      A[i + 1] = A[i];
      i = i - 1;
      A[i + 1] = k;
    }
    trace(A,n);

  }
  return 0;
}
