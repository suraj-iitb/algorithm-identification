#include <stdio.h>
#include <stdlib.h>

int main(){
  int i,j,key,loop,N;
  int *A;

  scanf("%d",&N);
  A=malloc(sizeof(int)*N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=1;i<N;i++){
    for(loop=0;loop<N;loop++){
      if(loop!=N-1)printf("%d ",A[loop]);
      else printf("%d\n",A[loop]);
    }
    key=A[i];
    j=i-1;
    while(j>=0&&A[j]>key){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;
  }
  for(loop=0;loop<N;loop++){
      if(loop!=N-1)printf("%d ",A[loop]);
      else printf("%d\n",A[loop]);
  }
  return 0;
}
