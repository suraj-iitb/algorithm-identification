#include <stdio.h>
#include <stdlib.h>
int main(){
  int i,j,v,N,*A,n;
  
  scanf("%d",&N);
  A=malloc(sizeof(int)*N);
  for(i=0;i<=N-1;i++){
    scanf("%d",&A[i]);
  }

  
  for(i=1;i<N;i++){
    //if(A[i]>A[i+1]){
    for(n=0;n<N-1;n++){
      printf("%d ",A[n]);
    }
    printf("%d\n",A[N-1]);
    
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
      
  }
  for(n=0;n<N-1;n++){
    printf("%d ",A[n]);
  }
  printf("%d\n",A[N-1]);
  free(A);

  return 0;
}
