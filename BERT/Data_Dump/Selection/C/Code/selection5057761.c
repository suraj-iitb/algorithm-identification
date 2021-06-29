#include <stdio.h>
#include <stdlib.h>

int main(){
  int A[100],B[100],N,i,j,minj,sum=0;
  scanf("%d",&N);
  if(N<1 || N>100) exit(1);

  for(i=0;i<N;i++)
    scanf("%d",&A[i]);

  for(i=0;i<N;i++){
    minj = i;
    for(j=i;j<N;j++){
      if(A[j] < A[minj])
        minj = j;
    }
      B[i] = A[i];
      A[i] = A[minj];
      A[minj] = B[i];
      if(minj!=i)sum++;
  }

  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",sum);
  return 0;
}
