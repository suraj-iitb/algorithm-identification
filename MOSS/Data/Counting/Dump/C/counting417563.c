#include<stdio.h>
#define N 2000000

unsigned int A[N];
unsigned int B[N];

int main(){

  int C[10000];

  int i,j,k,n;
  k=0;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(A[i]>k)k=A[i];
  }
  for(i=0;i<=k;i++)C[i]=0;
  for(j=1;j<=n;j++)C[A[j]]=C[A[j]]+1;
  for(i=1;i<=k;i++)C[i]=C[i]+C[i-1];
  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]=C[A[j]]-1;
  }

  for(i=1;i<=n;i++){
    if(i!=1)printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");

  return 0;
}
