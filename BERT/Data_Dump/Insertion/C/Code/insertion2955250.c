#include<stdio.h>
#include<stdlib.h>
int main(){
  int i,j,p,N,v;
  int *A;

  scanf("%d",&N);
  A=(int *)malloc(N*sizeof(int));
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<N;i++){
    if(i!=N-1){
      printf("%d ",A[i]);
    }
    else if(i==N-1){
      printf("%d",A[i]);
    }
  }
  printf("\n");
  
  for(i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;  
    for(p=0;p<N;p++){
      if(p!=N-1){
	printf("%d ",A[p]);
      }
      else if(p==N-1){
	printf("%d",A[p]);
      }
    }
    printf("\n"); 
  }
  free(A);
  return 0;
}

