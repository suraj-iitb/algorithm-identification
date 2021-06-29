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
  int n, i, j,k,v;
  int A[N+1];

  scanf("%d", &n);
 
  for ( i = 1; i <= n; i++ ) scanf("%d ", &A[i]);
  trace(A, n);
  for(i = 2 ;i <= n; i++){
    v = A[i];
    j = i-1;
    while( j >=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
     }
    for ( k = 1; k <= n; k++ ){ 
       if(k<n)printf("%d ",A[k]);
       else printf("%d",A[k]);
    } 
    printf("\n");
   }   
  return 0;
}
