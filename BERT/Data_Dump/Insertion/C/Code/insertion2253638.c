#include <stdio.h>

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
  int n, i, j, key;
  int A[N+1];
  scanf("%d", &n);

  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);
  
  trace(A, n);

  for(j = 1; j <= n; j++){
    key = A[j];
    i = j - 1;
    while(i > 0){
      if(A[i] > key){
	A[i+1] = A[i];
	i = i - 1;
      }
      else break;
    }
    A[i+1] = key;

    if(j >= 2) trace(A, n);
  }
  return 0;
}
