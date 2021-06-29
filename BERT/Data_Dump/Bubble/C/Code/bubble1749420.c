#include <stdio.h>

int main() {

  int a,N,i,j,A[100],count;

  while(1) {
    scanf("%d",&N);
    if(N<1 || 100<N) printf("error\n");
    else break;
  }

  while(1) {
    count = 0;
    for(i=0; i<N; i++) scanf("%d",&A[i]);
    for(i=0; i<N; i++) if(A[i]<0 || 100<A[i]) count++;
    if(count==0) break;
    else printf("error\n");
  }

  for(i=0; i<N-1; i++) {
    for(j=N-1; j>=0; j--) {
      if(A[j] < A[j-1]) {
        a = A[j];
        A[j] = A[j-1];
        A[j-1] = a;
        count++;
      }
    }
  }

  for(i=0; i<N; i++) {
    printf("%d",A[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}
