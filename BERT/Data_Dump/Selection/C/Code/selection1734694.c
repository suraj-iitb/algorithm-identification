#include <stdio.h>

#define N 100

int main()
{

  int i, j, A[N], n, minj, tmp, count = 0;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
  }

  for(i=0; i<=n-1; i++){
    minj = i;
    for(j=i; j<=n-1; j++){
      if(A[j] < A[minj]) minj = j;
    }
    if(A[i]>A[minj]){
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
    count++;
    }
  }

  for(j=0; j<n-1; j++){
    printf("%d ", A[j]);
  }

  printf("%d", A[n-1]);
  printf("\n");
  printf("%d\n", count);

  return 0;
}
