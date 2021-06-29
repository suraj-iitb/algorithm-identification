#include<stdio.h>

int main(){
  int N,i,j,key;
  int A[1000];
  scanf("%d",&N);

  for(j=0;j<N;j++){
    scanf("%d",&A[j]);
  }
  for(j=0;j<N-1;j++){
    printf("%d ",A[j]);
  }
  printf("%d",A[N-1]);
  printf("\n");
  
  for(i=1;i<N;i++){
    
    key=A[i];
    j=i-1;
    
    while(j>=0&&A[j]>key){
      A[j+1]=A[j];
      j--;
     
      A[j+1]=key;
      
    }
    for(j=0;j<N-1;j++){
      printf("%d ",A[j]);
    }
    printf("%d",A[N-1]);
    
    printf("\n");
  }

  return 0;
}

