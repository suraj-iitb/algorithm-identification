#include<stdio.h>
#include<stdlib.h>

int main(){
  int N,i,j,key;
  int *A;

  scanf("%d",&N);
  A=(int *)malloc(sizeof(int)*N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(j=0;j<N;j++){
    key=A[j];
    i=j-1;
    while(i>=0 && A[i]>key){
      A[i+1]=A[i];
      i--;
    }
    A[i+1]=key;


    for(i=0;i<N-1;i++){
      printf("%d ",A[i]);
    }
    printf("%d\n",A[N-1]);
  }
  free(A);

  return 0;
}
