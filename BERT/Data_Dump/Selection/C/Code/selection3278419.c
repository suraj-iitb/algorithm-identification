#include <stdio.h>
#include <stdlib.h>
int main(){
  int i,N,j,*A,minj,for_change,times=0;

  scanf("%d",&N);
  A = (int *)malloc(N * sizeof(int));

  for(i = 0 ; i < N ; i++) scanf("%d",&A[i]);

  for(i = 0 ; i < N-1 ; i++){
    minj = i;
    for(j = i ; j <= N-1 ; j++){
      if(A[j] < A[minj]) minj = j; } 
    for_change = A[i];
    A[i] = A[minj];
    A[minj] = for_change;
    if(i != minj) times++; }
  
  for(j = 0 ; j < N-1 ; j++) printf("%d ",A[j]);
  printf("%d\n",A[N-1]);
  printf("%d\n",times);

  free(A);

  return 0;
}
