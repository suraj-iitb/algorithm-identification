#include<stdio.h>
#include<stdlib.h>

int main(){

  int i,j,k,N,key;
  int *A;

  scanf("%d",&N);
  A=(int *)malloc(N*sizeof(int));

  for(i=0;i<N;i++)scanf("%d",&A[i]);
  for(j=1;j<N;j++){
    key=A[j];
    i=j-1;
    for(k=0;k<N;k++){
      if(k!=N-1)printf("%d ",A[k]);
      else printf("%d\n",A[k]);
    }
    while(i>=0 && A[i]>key){
      A[i+1]=A[i];
      i=i-1;
    }
    A[i+1]=key;
  }

  for(k=0;k<N;k++){
    if(k!=N-1)printf("%d ",A[k]);
    else printf("%d\n",A[k]);
  }

  free(A);

}
