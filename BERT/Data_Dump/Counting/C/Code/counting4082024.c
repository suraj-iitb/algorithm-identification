#include<stdio.h>

int main(){
  
  int i, n;
  int k=10000;
  int A[2000000], B[2000000], C[10000]={};
  scanf("%d",&n);
  for(i=1;i<n+1;i++)
    scanf("%d",&A[i]);
  for(i=1;i<n+1;i++)
    C[A[i]]++;
  for(i=1;i<k+1;i++)
    C[i]=C[i]+C[i-1];
  for(i=n;i>=1;i--){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }
  for(i=1;i<n+1;i++){
    if(i!=n) printf("%d ",B[i]);
    else printf("%d\n",B[i]);
  }
  return 0;
}

