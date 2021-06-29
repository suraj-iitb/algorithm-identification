#include <stdio.h>

int main(){

  int i,j,v,a,N;
  int A[100];

  scanf("%d",&N);

  for(i=0;i<N;i++)scanf("%d",&A[i]);

  for (i=1;i<=N-1;i++){
    for(a=0;a<N;a++){
      if(a!=N-1)printf("%d ",A[a]);
      else printf("%d\n",A[a]);
    }
    v=A[i];
    j=i-1;
    while (j>=0 && A[j]>v){
      A[j+1] =A[j];
      j--;
      }
    A[j+1]=v;
    }

  for(a=0;a<N;a++){
      if(a!=N-1)printf("%d ",A[a]);
      else printf("%d\n",A[a]);
    }
}

