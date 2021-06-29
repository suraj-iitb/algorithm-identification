#include <stdio.h>

int main(){
  int i,j,minj,N,A[100],B[100],count=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(i!=minj)
      count++;
    
    B[i]=A[i];
    A[i]=A[minj];
    A[minj]=B[i];
  }

  for(j=0;j<N-1;j++){
    printf("%d ",A[j]);
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",count);

  return 0;
}
