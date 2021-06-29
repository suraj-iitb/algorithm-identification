#include <stdio.h>
#include <stdlib.h>
#define N 100
#define Y 1000
int main(){
  int i,j,k,v,A[N],n;
  scanf("%d",&n);
  if(n>N)exit(8);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(A[i]>Y || A[i]<0)exit(8);
  }
  for(i=1;i<=n;i++){
    for(k=0;k<n;k++){
      if(k==n-1)printf("%d",A[k]);
      else printf("%d ",A[k]);
    }
    printf("\n");
    v=A[i];
    j=i-1;
    while (j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
  }
  return 0;
}

