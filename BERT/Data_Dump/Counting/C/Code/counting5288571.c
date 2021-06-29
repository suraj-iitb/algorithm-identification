#include <stdio.h>
int main(void){
  int n,k,i,j;
  scanf("%d",&n);
  int A[n];
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }
  k = 0;
  for(i=0;i<n;i++){
    if(A[i]>k){
      k = A[i];
    }
  }
  int C[k+1];
  for(i=0;i<=k;i++){
    C[i]=0;
  }
  for (j=1;j<=n;j++){
    C[A[j]] = C[A[j]]+1;
  }
  for(i=1;i<=k;i++){
    C[i] = C[i] + C[i-1];
  }
  int B[n];
  for(j=n;j>0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]] - 1;
  }
  for(i=1;i<=n;i++){
    if (i==n){
      printf("%d\n",B[i]);
    }
    else{
      printf("%d ",B[i]);
    }
  }
}
