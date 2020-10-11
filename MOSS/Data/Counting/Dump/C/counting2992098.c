#include <stdio.h>
#include <stdlib.h>
#define N 2000001
#define A_IN 10000

int A[N],B[N],C[A_IN+1];
void CountingSort(int A[],int B[],int n){
  int i,j;
  for(i=0;i<=A_IN;i++)C[i]=0;
  for(j=1;j<=n;j++)C[A[j]]++;
  for(i=1;i<=A_IN;i++)C[i]=C[i]+C[i-1];
  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}

int main(){
  int i,j,n;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }
  CountingSort(A,B,n);

  for(i=1;i<=n;i++){
    if(i==n)printf("%d",B[i]);
    else printf("%d ",B[i]);
  }
  printf("\n");

  return 0;
}

