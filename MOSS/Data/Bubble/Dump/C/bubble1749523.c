#include <stdio.h>
#define N 100

int main()
{
  
  int A[N], i, n, num, count = 0, flag = 1;

  scanf("%d", &n);
  for(i = 0; i < n; i ++) scanf("%d", &A[i]);

  while(flag){
    flag = 0;
    for(i = n-1; i > 0; i--){
      if(A[i] < A[i-1]){
	num = A[i-1];
	A[i-1] = A[i];
	A[i] = num;
	flag = 1;
	count += 1;
      }
    }
  }

  for(i = 0; i < n; i++){
    if(i == n-1) printf("%d", A[i]);
    else printf("%d ", A[i]);
  }
  printf("\n%d\n", count);

  return 0;
}
