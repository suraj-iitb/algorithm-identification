#include <stdio.h>
#include <stdlib.h>

int main (){
  int n, q, cnt=0;
  scanf("%d", &n);
  int *A = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  scanf("%d", &q);
  int *B = (int *)malloc(sizeof(int) * q);
  for (int i = 0; i < q; i++){
    scanf("%d", &B[i]);
  }

  for (int i = 0; i < q; i++){
    for (int j = 0; j < n; j++){
      if (A[j] == B[i]) {
	cnt++;
	break;
      }
    }
  }
  
  printf("%d\n", cnt);

  free(A);
  free(B);
  
  return 0;
}

