#include <stdio.h>
#include <stdlib.h>
int main()
{
  int *A,i,j,k,N,v;

  scanf("%d",&N);
  A = (int *)malloc(N * sizeof(int));
  for(i = 0 ; i < N ; i++) scanf("%d",&A[i]);
  
  for(i = 1 ; i < N ; i++){
    for(k=0 ; k < N-1 ; k++) printf("%d ",A[k]);
    printf("%d\n",A[k]);
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--; }
    A[j+1] = v;
  }
  
 for(k=0 ; k < N-1 ; k++) printf("%d ",A[k]);
    printf("%d\n",A[k]);
 
      
  return 0;
}
