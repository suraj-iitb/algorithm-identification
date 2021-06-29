#include <stdio.h>

int main() {

  int a,b=0,i,j,N,A[100],count,minj;

  while(1) {
    scanf("%d",&N);
    if(N<0 || 100<N) printf("error\n");
    else break;
  }

  while(1) {
    count=0;
    for(i=0; i<N; i++) scanf("%d",&A[i]);
    for(i=0; i<N; i++) if(A[i]<0 || 100<A[i]) count++;
    if(count!=0) printf("error\n");
    else break;
  }

  for(i=0; i<N; i++) {
    minj = i;
    for(j=i; j<N; j++) {
      if(A[j] < A[minj]) {
        minj = j;
        count++;
      }
    }
    if(count!=0) {
      a = A[i];
      A[i] = A[minj];
      A[minj] = a;
      b++;
      count = 0;
    }
  }

  for(i=0; i<N; i++) {
    printf("%d",A[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",b);

  return 0;
}
