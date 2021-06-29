#include<stdio.h>

int main(){
  int i,j,N,key,A[100];
  
  scanf("%d",&N);
  
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
 
  for(i=0;i<N;i++){
    if(i!=N-1)printf("%d ",A[i]);
    else printf("%d",A[i]);
  }
  printf("\n");

  for(i=1;i<N;i++){
    key=A[i];
    j=i-1;

    while(j>=0 && A[j]>key){  
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;

    for(j=0;j<N;j++){
      if(j!=N-1) printf("%d ",A[j]);
      else printf("%d",A[j]);
    }
   printf("\n");
  }
  return 0;
} 
