#include <stdio.h>
#define N 100

int main()
{

  int A[N], i, j, k, n, v;

  /* input data */
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);

    /* output 1st data */
    if(i != n-1) printf("%d ", A[i]);
    else printf("%d",A[i]);
  }
  printf("\n");

  /* sort */
  for(i = 1; i <= n-1; i++){  
    v = A[i];
    j = i-1;
    while(j >=0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

    /* output 2,3,,,,nth data */
    for(j = 0; j < n; j++){
      if(j != n-1) printf("%d ", A[j]);
      else printf("%d", A[j]);
    }
    printf("\n");
  }
  return 0;
}
