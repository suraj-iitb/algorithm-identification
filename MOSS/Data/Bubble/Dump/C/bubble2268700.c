#include <stdio.h>


static const int N =1000;

void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main()
{
  int n, i, j, swap, count = 0;
  int A[N];
  scanf("%d", &n);

  for(i = 0; i < n; i++) scanf("%d", &A[i]);

  for(i = 0; i <= n-1; i++){
    for(j = n-1; j >= i+1; j--){
    if( A[j] < A[j-1]){
      swap = A[j];
      A[j] = A[j -1];
      A[j - 1] = swap;
	count++;
    }
    }
  }
  trace(A, n);
  printf("%d\n", count);
  
  return 0;
}
