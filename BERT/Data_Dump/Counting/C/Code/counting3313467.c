#include <stdio.h>
#define N 10000

int A[2000001],B[2000001],C[N];

int main(){
  int i,j,n;

  scanf("%d",&n);
  for(i=1;i<n+1;i++){
    scanf("%d",&A[i]);
  }
 
  for(i=0;i<N;i++)C[i]=0;

  for(j=1;j<n+1;j++)C[A[j]]+=1;

  for(i=0;i<N;i++)C[i]+=C[i-1];

  for(j=n+1;j > 0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]-=1;
  }

  
  for(i=1;i<n;i++){
  
    printf("%d ",B[i]);
     
  }
  printf("%d",B[i]);
  printf("\n");

  return 0;
}

