#include<stdio.h>
#include<stdlib.h>

int main(){

  int i,j,k,N,*A,min,cnt=0;

  scanf("%d",&N);
  A=(int *)malloc(N*sizeof(int));

  for(i=0;i<N;i++)scanf("%d",&A[i]);

  for(i=0;i<N-1;i++){
    min=i;
    for(j=i;j<N;j++){
      if(A[j]<A[min]){
        min=j;
      }
    }
    if(min!=i){
      cnt++;
      k=A[i];
      A[i]=A[min];
      A[min]=k;
    }
  }
  for(i=0;i<N;i++){
    if(i!=N-1)printf("%d ",A[i]);
    else printf("%d\n",A[i]);
  }
  printf("%d\n",cnt);
  return 0;
}
