#include <stdio.h>
#include <stdlib.h>

int main()
{
int N, i, j, tmp;
int count=0;

scanf("%d", &N);
if (N<1 || N>100) exit(1);

int A[N];

for (i=0;i<N;i++) {
  scanf("%d", &A[i]);
}

int flag = 1; // 逆の隣接要素が存在する
i = 0;
while (flag==1) {
    flag = 0;
    for (j=N-1; j>=i+1; j--) {
      if (A[j] < A[j-1]) {
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        flag = 1;
        count++;
      }
    }
    i++;
}

for (i=0;i<=N-1;i++) {
  if (i==N-1) printf("%d", A[i]);
  else printf("%d ", A[i]);
}
printf("\n%d\n", count);

  return 0;
}

