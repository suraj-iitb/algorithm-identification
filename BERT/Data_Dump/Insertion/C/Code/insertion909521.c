#include <stdio.h>
#include <stdlib.h>

int main(){
  int i,j,k,key,N,A[100];

  scanf("%d",&N);
  if (N<1||N>100){
    printf("N ha 1-100 dene\n");
    exit(1);
  }
  for (i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for (i=1;i<=N;i++){
    for (k=0;k<N;k++){
      printf("%d",A[k]);
      if (k!=N-1){
        printf(" ");
      }
    }
    printf("\n");
    key = A[i];
    j = i-1;
    while (j>=0 && A[j]>key){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;
  }
  return 0;
}
