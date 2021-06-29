#include<stdio.h>
#include<stdlib.h>
#define MAX 2000000
#define AMAX 10000
int main(){
  int *A,*B,C[AMAX+1],n,i,j;
   scanf("%d",&n);
  A=malloc(sizeof(int)*(n+1));
  B=malloc(sizeof(int)*(n+1));
 
  for(i=0;i<=AMAX;i++)C[i]=0;
  for(j=1;j<=n;j++){
  scanf("%d",&A[j]);
  C[A[j]]++;
  }
  
 

  for(i=1;i<=AMAX;i++)C[i]+=C[i-1];
  for(j=1;j<=n;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
      }
  for(i=1;i<=n-1;i++)printf("%d ",B[i]);
    printf("%d\n",B[n]);
  
  return 0;
}

