#include <stdio.h>

int main(){

  int i,j,A[1000],N,v;

  scanf("%d",&N);

  for(i=0;i<=N-1;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<=N-1;i++){
    v = A[i];
    j = i - 1;

    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

    for(j=0;j<N-1;j++){
      printf("%d ",A[j]);
    }
    printf("%d",A[N-1]);
    printf("\n");

  }
  return 0;
}
