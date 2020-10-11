#include<stdio.h>

#define N 2000001

int n;
int A[N],B[N];

void CountingSort(int* A,int* B,int k){
  int i,j;
  int C[k];
  for(i=0;i<=k;i++){
    C[i]=0;
  }
  for(j=1;j<=n;j++){
    C[A[j]]=C[A[j]]+1;
  }
  for(i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]=C[A[j]]-1;
  }
}


main(){
  int i,max=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(max<A[i])max=A[i];
  }
  CountingSort(A,B,max);
  for(i=1;i<=n-1;i++){
    printf("%d ",B[i]);
  }
  printf("%d",B[n]);
  printf("\n");
  return 0;
}
