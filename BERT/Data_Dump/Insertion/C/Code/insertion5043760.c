#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(){
  int i,j,v,n,k,A[N];
  scanf("%d",&n);
  for(i=0;i<=n-1;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=n-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
      v=A[j+1];
    }
    for(k=0;k<=n-2;k++){
      printf("%d ",A[k]);
    }
    printf("%d\n",A[n-1]);
  }
  return 0;
}

