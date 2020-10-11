#include <stdio.h>

int main()
{
  int i, j, A[100], N, v, minj, count=0;

  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }

  for(i=0; i<=N-1; i++){
    minj=i;
    for(j=i; j<=N-1; j++){
      if(A[j]<A[minj]){
        minj=j;
      }
    }
    v=A[i];
    A[i]=A[minj];
    A[minj]=v;
    if(A[i]<A[minj]) count++;
  }
  for(i=0; i<N; i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);
  return 0;
}
