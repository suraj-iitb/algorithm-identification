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
  int n, i, j,stack;
  int A[N+1];
  scanf("%d", &n);

  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);
  
   for(i=1;i<=n;i++){
    stack=A[i];
    j=i-1;
    while(j>=0 && A[j]>stack){
      A[j+1]=A[j];
      j--;
      A[j+1]=stack;
    }
    trace(A,n);
  }
  return 0;
}
