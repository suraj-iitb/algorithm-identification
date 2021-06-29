#include <stdio.h>
#include <stdlib.h>

int main (){
  int n, minj, cnt = 0, j;
  scanf("%d", &n);
  int *A = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  for (int i = 0; i < n; i++){
    minj = i;
    for (int j = i; j < n; j++){
      if (A[j] < A[minj]){
	minj = j;
	//cnt++;
      }
    }
    if (i != minj) cnt++;
    int t = A[i];
    A[i] = A[minj];
    A[minj] = t;
    //cnt++;
  }

  for (int i = 0; i < n; i++){
    if (i == n-1) printf("%d\n", A[i]);
    else printf("%d ", A[i]);
  }

  printf("%d\n", cnt);

  free(A);
  
  return 0;
}

