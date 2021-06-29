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
  int key;
  int A[N+1];
  scanf("%d", &n);

  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);
  
  trace(A, n);
  for(j = 2; j <= n; j++){
    	key = A[j];
    for(i = j -1; i >= 1; i--){ 

	if(key < A[i]){
	A[i+1] = A[i];
	A[i] = key;
      }
    }
    trace(A, n);
  }
  return 0;
}
