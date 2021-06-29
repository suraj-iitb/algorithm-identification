#include <stdio.h>

int main(){
  int i,j,N,A[100],n,v;

  scanf("%d",&N);

  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }

  for(i=1; i<=N; i++){
    for(n=0; n<N-1; n++){
      printf("%d ",A[n]);
    }
    printf("%d\n",A[n]);
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
  }

  return 0;
}
