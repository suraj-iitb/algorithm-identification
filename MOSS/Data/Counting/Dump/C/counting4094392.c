#include <stdio.h>
#include <stdlib.h>

int main (){
  int n,i,*A,B[10001]={},*C,j;
  scanf("%d",&n);
  A=(int *)malloc(sizeof(int)*(n+1));
  C=(int *)malloc(sizeof(int)*(n+1));
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    B[A[i]]++;
  }
  for(i=1;i<10001;i++){
    B[i]+=B[i-1];
  }
  for(i=n;i>=0;i--){
    C[B[A[i]]]=A[i];
    B[A[i]]--;    
  }
  for(i=1;i<=n;i++){
    if(i-1) printf(" ");
    printf("%d",C[i]);
  }
  printf("\n");
  free(A);
  free(C);
  return 0;
}
  
  
  

