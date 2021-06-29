#include<stdio.h>

static const int N = 1000;

void trac(int A[], int n){
  int i;
  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(){
  int k, i, j,key;
  int A[N+1];
  scanf("%d", &k);

  for ( i = 1; i <=k; i++ ) scanf("%d", &A[i]);
  
  trac(A, k);
  /*

    your code

   */
  for(j=2;j<=k;j++){
    key=A[j];
    i=j-1;
    while(i>=0 && A[i]>key){
      A[i+1]=A[i];
      i=i-1;
    }
    A[i+1]=key;
    trac(A,k);
  }
  return 0;
}
