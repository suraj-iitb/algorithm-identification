#include <stdio.h>
#include <stdlib.h>

int main()
{
int N, i, j, minj, tmp;
int count=0;

scanf("%d", &N);
if (N<1 || N>100) exit(1);

int A[N];

for (i=0;i<N;i++) {
  scanf(" %d", &A[i]);
}

for (i=0;i<=N-1;i++) {
  minj=i;
  for(j=i;j<=N-1;j++) {
    if(A[j]<A[minj]) {
      minj = j;
    }
  }
  if(i!=minj) count++;
  tmp = A[i];
  A[i] = A[minj];
  A[minj] = tmp;
}

for (i=0;i<=N-1;i++) {
if (i==N-1) printf("%d",A[i]);
else printf("%d ", A[i]);
}
printf("\n%d\n", count);

  return 0;
}

