#include<stdio.h>
#define MAX1 2000000
#define MAX2 10000

int main(){
  int N,A[MAX1],B[MAX1],C[MAX2];
  int i;
  
  scanf("%d",&N); 
  for(i=0;i<N;i++) scanf("%d",&A[i]);  
  for(i=0;i<MAX2;i++) C[i]=0;
  for(i=0;i<N;i++) C[A[i]]++;
  for(i=1;i<MAX2;i++) C[i]=C[i]+C[i-1];
  for(i=N-1;i>=0;i--){
      B[C[A[i]]-1]=A[i];
      C[A[i]]--;  
  }

  for(i=0;i<N;i++){
    printf("%d",B[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n");

  return 0;
}

