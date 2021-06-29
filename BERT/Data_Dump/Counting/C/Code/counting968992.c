#include<stdio.h>

int A[2000001],B[2000001],C[100001];

int main(){
  int n,i,j,k = 0;

  
  scanf("%d", &n);
  for( i = 1; i <= n; i++ ) {
    scanf("%d", &A[i]);
    if(A[i]>k){
      k=A[i];
    }
  }
  
  for(i=0;i<=k;i++){
    C[i]=0;
  }
  
  for(j=1;j<=n;j++){
    C[A[j]]++;
  }
  for(i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=n;j>0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);
  
  return 0;
}
