#include <stdio.h>
#include <stdlib.h>
int main()
{
  int i,j,v,A[100],k,N;

  scanf("%d",&N);
  if(N < 0 || N > 100) exit(2);
  for(i = 0; i < N ; i++){
    scanf("%d",&A[i]);
    if(A[i] < 0 || A[i] > 1000) exit(2);
  }

  for(k = 0 ; k < N ; k++){
    printf("%d",A[k]);
    if(k != N-1) printf(" ");
  }
  printf("\n");

  for(i = 1 ; i <= N-1 ; i++){
    v = A[i];
    j = i-1;

    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

    for(k = 0 ; k < N ; k++){
      printf("%d",A[k]);
    if(k != N-1) printf(" ");
    }
    printf("\n");
  }

  return 0;
}
