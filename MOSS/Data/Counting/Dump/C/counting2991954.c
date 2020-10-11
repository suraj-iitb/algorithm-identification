#include<stdio.h>
void CountingSort(int *,int *,int,int);
int main(){
  int i,n,k=0;
  scanf("%d",&n);
  int A[n];
  int B[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(A[i]>k) k=A[i];
  }
  CountingSort(A,B,k,n);
  for(i=1;i<n+1;i++){
    if(i==n) printf("%d\n",B[i]);
    else printf("%d ",B[i]);
    
  }
  return 0;
}

void CountingSort(int *A, int *B, int k,int n){
  int C[k+1],i,j;
  for(i = 0;i<k+1;i++){
    C[i] = 0;
  }
  /* C[i] に i の出現数を記録する */
  for(j=0;j<n;j++){
    C[A[j]]++;
  }
  /* C[i] に i 以下の数の出現数を記録する*/
  for(i=1;i<=k;i++){
    C[i] = C[i] + C[i-1];
  }
  for(j = n-1;j>=0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
