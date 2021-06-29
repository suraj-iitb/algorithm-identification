#include<stdio.h>
#include<stdlib.h>

int main(){

  int i,j,k,N,*A,cnt=0;

  scanf("%d",&N);
  A=(int *)malloc(N*sizeof(int));

  for(i=0;i<N;i++)scanf("%d",&A[i]);

  for(i=0;i<N-1;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
        cnt++;
        k=A[j-1];
        A[j-1]=A[j];
        A[j]=k;
      }
    }
  }

  for(i=0;i<N;i++){
    if(i!=N-1)printf("%d ",A[i]);
    else printf("%d\n",A[i]);
  }
  printf("%d\n",cnt);
  return 0;
}
