#include <stdio.h>
int main () {
  int i,j,k,N,A[100],key;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(k=0;k<N-1;k++) printf("%d ",A[k]);
  printf("%d\n",A[N-1]);
  for(i=1;i<=N-1;i++){
    key = A[i];
    j = i-1;
    while(j>=0 && A[j] > key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    for(k=0;k<N-1;k++) printf("%d ",A[k]);
    printf("%d\n",A[N-1]);
  }
  return 0;
}

