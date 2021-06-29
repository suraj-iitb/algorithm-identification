#include<stdio.h>
#include<stdlib.h>
#define N 10000

int main(){
  int i,n,*A,*B;
  int C[N+1];
  scanf("%d",&n);
  
  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);
  
  for(i=0 ; i<n ; i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0 ; i<N+1 ; i++){
    C[i]=0;
  }
  for(i=0 ; i<n ; i++){
    C[A[i]]++;
  }
  for(i=1 ; i<N+1 ; i++){
    C[i] = C[i] + C[i-1];
  }
  for(i=n-1 ; i>=0 ; i--){
    B[C[A[i]]-1] = A[i];
    C[A[i]]--;
  }

  for(i=0 ; i<n ; i++){
    if(i<n-1)  printf("%d ",B[i]);
    else printf("%d\n",B[i]);
  }
  return 0;
}

