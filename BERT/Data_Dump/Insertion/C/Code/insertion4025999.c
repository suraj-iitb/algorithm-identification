#include <stdio.h>

int main(){

  int N,A[100],a,b,i,j,n,v;
  
  scanf("%d",&N);
  for (a = 0;a < N;a++) scanf("%d",&A[a]);
  
  for (i = 1;i < N;i++){
    for (b = 0;b < N-1;b++)  printf("%d ",A[b]);
    printf("%d\n",A[N-1]);
    v = A[i];
    j = i - 1;
    while (j >= 0 && A[j]  > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  }

  for (b = 0;b < N-1;b++)  printf("%d ",A[b]);
  printf("%d\n",A[N-1]);

  return 0;
}

