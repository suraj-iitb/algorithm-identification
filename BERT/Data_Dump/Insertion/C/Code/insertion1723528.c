#include <stdio.h>
#define n 1000
int main()
{
  int N, A[n], i, v, j, p;

  scanf("%d",&N);
  for(i=0; i<N; i++) scanf("%d",&A[i]);
  
  for(i=1; i<N; i++){
    v = A[i];
    j = i - 1;
    for(p=1; p<=N; p++){
      if ( p > 1 ) printf(" ");
      printf("%d", A[p-1]);
    }
    printf("\n");
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
  }
  for(p=1; p<=N; p++){
    if ( p > 1 ) printf(" ");
    printf("%d", A[p-1]);
  }
  printf("\n");
  
  return 0;
}
