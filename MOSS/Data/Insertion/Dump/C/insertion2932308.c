#include<stdio.h>
#include<stdlib.h>

int main(){
  int i,j,v,k,N;
  int *A;
  scanf("%d",&N);
  A = (int *)malloc(sizeof(int)*N);
  for(k=0;k<N;k++){
    scanf("%d",&A[k]);
  }
   printf("%d",A[0]);
    for(k=1;k<N;k++) printf(" %d", A[k]);
    printf("\n");
  for(i=1;i<=N-1;i++){
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    printf("%d",A[0]);
    for(k=1;k<N;k++) printf(" %d", A[k]);
    printf("\n");
  }
  
  return 0;
}

