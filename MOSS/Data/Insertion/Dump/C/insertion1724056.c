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
  int n, i, j,a;
  int A[N+1];
  scanf("%d", &n);

  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);
  
    trace(A, n);
  /*

    your code

   */

  for(i=1;i<n;i++){
 
   for(j=i+1;j>1;j--){

    if(A[j]<A[j-1]){

      a=A[j];
      A[j]=A[j-1];
      A[j-1]=a;

}
    }

   trace(A,n);

}

  return 0;
}
