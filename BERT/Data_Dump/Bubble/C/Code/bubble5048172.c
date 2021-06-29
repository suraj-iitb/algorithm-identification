#include <stdio.h>
#include <stdlib.h>

int main (){
  int n, flag = 1, cnt = 0;
  scanf("%d", &n);
  int *A = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++){
    scanf(" %d", &A[i]);
  }
  
  while (flag){
    flag = 0;
    for (int i = n-1; i > 0; i--){
      if (A[i] < A[i-1]){
	int t = A[i];
	A[i] = A[i-1];
	A[i-1] = t;
	flag = 1;
	cnt++;
      }
    }
  }

  for (int i = 0; i < n; i++){
    if (i == n-1) printf("%d\n", A[i]);
    else printf("%d ", A[i]);
  }
  printf("%d\n",cnt);

  free(A);
  return 0;
}

