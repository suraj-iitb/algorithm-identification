#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(){
  
  int i,j,k,A[N],v,n;
  
  scanf("%d",&n);
  if(n<1 || n>100){
    exit(1);
  }
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(A[i]<0 || A[i]>1000){
      exit(1);
    }
  }

  for(i=0;i<n;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    
    A[j+1]=v;

    for(k=0;k<n;k++){
      printf("%d",A[k]);
      if(k==n-1) break;
      printf(" ");
    }
    printf("\n");
  }
  
  return 0;
}
