#include <stdio.h>
#include <stdlib.h>

int main()
{
int i, j, v, k;
int N;

scanf("%d", &N);
if (N<0 || N>100) exit(1);

int A[N];

for (i=0;i<N;i++) {
  scanf("%d", &A[i]);
}

for (i=0;i<=N-1;i++) {
  if (i==N-1) printf("%d", A[i]);
  else printf("%d ", A[i]);
}
printf("\n");

 for (i=1; i<=N-1;i++) {
  v=A[i];
  j=i-1;
  while(j>=0&&A[j]>v) {
    A[j+1]=A[j];
    j--;
  }
  A[j+1]=v;

  for (k=0;k<=N-1;k++) {
  if (k==N-1) printf("%d", A[k]);
  else printf("%d ", A[k]);
  }
  printf("\n");
}

  return 0;
}

