#include<stdio.h>
#define N 100
int main(){
  int i,j,key,n,A[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    key=A[i];
    j=i-1;
    while(j>=0&&key<A[j]){
      A[j+1]=A[j];
      j--;
      A[j+1]=key;
    }
    for(j=0;j<n;j++){
      if(j>=0 && j<n-1){
 printf("%d ",A[j]);
      }
      if(j==n-1){
 printf("%d",A[j]);
      }
    }
    printf("\n");
  }
    return 0;
  }
