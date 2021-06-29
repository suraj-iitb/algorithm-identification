#include <stdio.h>
#include <stdlib.h>
 
#define N 2000001
#define k 10000
 
int main(){
 
    int n,i,j;
    int *A,*B,C[N];
 
    scanf("%d",&n);
 
    A = malloc(sizeof(int) *n+1);
    B = malloc(sizeof(int) *n+1);
 
    for(i=0 ; i<k ; i++) C[i]=0;
 
    for(i=0 ; i<n ; i++){
      scanf("%d",&A[i]);
      C[A[i]]++;
    }
 
    for (i=1; i <=k ; i++) {
      C[i]+=C[i-1];
    }
 
    for(j=n-1 ; j>=0 ; j--){
      B[C[A[j]]]=A[j];
      C[A[j]]--;
    }
 
    for(i=1 ; i<=n ; i++){
      printf("%d",B[i]);
      if(i<n) printf(" ");
    }
 
    printf("\n");
 
    return 0;
 
}
