#include <stdio.h>

#define N 100

int main()
{

  int i, j, n, A[N], flag, count = 0, tmp;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
  }

  flag = 1;

  while(flag){
    flag = 0;
    for(j=n-1; j>=1; j--){
      if(A[j] < A[j-1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	flag = 1;
	count++;
      }
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
