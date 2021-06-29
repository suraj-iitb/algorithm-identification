#include <stdio.h>
#define N 100
int main(){
  int A[N];
  int i,j,key,x,s,k;
  scanf("%d",&x);
  for(i=0;i<x;i++){
    scanf("%d",&j);
    A[i]=j;
  }
   for(s=0;s<x-1;s++){
      printf("%d ",A[s]);
      }
   printf("%d",A[s]);
    printf("\n");
  
  for(i=0;i<x-1;i++){

    for( k=i;k>=0;k--){

    if(k>=0 && A[k]>A[k+1]){
      key=A[k];
      A[k]=A[k+1];
      A[k+1]=key;
    }
    }
    for(s=0;s<x-1;s++){
      printf("%d ",A[s]);
      }
    printf("%d",A[s]);
    printf("\n");
  }
  return 0;
}

