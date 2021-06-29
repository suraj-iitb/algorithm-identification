#include <stdio.h>

int A[2000001],B[2000001],C[10001];

int main(){
  
  int n,i,k=0;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(k<A[i])k=A[i];
  }

  for(i=0;i<k+1;i++){
    C[i]==0;
  }

  for(i=0;i<n;i++){
    C[A[i]]++;
  }

  for(i=0;i<k+1;i++){
    C[i]=C[i]+C[i-1];
  }

  for(i=n-1;i>=0;i--){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }

  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i!=n)printf(" ");
  }

  printf("\n");

  return 0;
}

