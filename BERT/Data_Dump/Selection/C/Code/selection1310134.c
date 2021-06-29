#include <stdio.h>
 
int main()
{
   
  int A[100];
  int i=0, j=0, N=0, minj=0,a, n=0;
   
  scanf("%d", &N);
  for(i=0; i<N; i++){
    scanf("%d", &A[i]);
  }
   
  for(i=0; i<=N-1; i++){
    minj = i;
    for(j=i; j<=N-1; j++){
      if(A[j] < A[minj]){
    minj = j;
      }
    }
    a = A[i];
    A[i] = A[minj];
    A[minj] = a;
    if(minj != i){
      n++;
    }
  }
  for(i=0; i<N; i++){
    printf("%d", A[i]);
    if(i == N-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n", n);
  return 0;
}
