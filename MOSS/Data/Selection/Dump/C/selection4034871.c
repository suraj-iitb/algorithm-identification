#include <stdio.h>

int main () {
  int i,j,n,minj,N,tmp,count=0;

  scanf("%d",&N);

  int A[N];
  
   for(i=0;i<N;i++) {
    scanf("%d",&A[i]);
  }

  for(i=0;i<=N-1;i++) {
    minj =i;
    for(j=i;j<=N-1;j++) {
      if(A[j] < A[minj]) minj = j;
    }
    if(minj!=i) {
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
    count++;
    }
  }

  for(i=0;i<N;i++) {
    if(i==0) printf("%d",A[i]);

    else printf(" %d",A[i]);
    if(i==N-1) printf("\n");
  }
  printf("%d\n",count);

  return 0;
  }

