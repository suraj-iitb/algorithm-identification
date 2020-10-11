#include <stdio.h>
#include <stdlib.h>
int A[2000001],B[2000001],C[10001],i,j,k=10000;
void CountingSort(int A[],int B[],int n){
  for(i=0;i<=k;i++){
    C[i]=0;
  }for(j=1;j<=n;j++){
    C[A[j]]++;
  }for(i=0;i<=k;i++){
    C[i] = C[i] + C[i-1];
  }for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}
  
int main(){
  int n;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
     scanf("%d",&A[i]);
  }
  CountingSort(A,B,n);
  for(i=1;i<n;i++){
  printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);
  return 0;
}

