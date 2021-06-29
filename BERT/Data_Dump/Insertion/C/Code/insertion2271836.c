#include <stdio.h>

#define N 1000

int main(){
  int n, i, j, k, key;
  int A[N];
  scanf("%d", &n);

  for (i = 0; i < n; i++ ) scanf("%d", &A[i]);

  for (i = 0; i < n; i++) {
    key = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > key) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    for (k = 0; k < n; k++) {
      if (k > 0){
        printf(" ");
      }
      printf("%d",A[k]);
    }
    printf("\n");
  }
  return 0;
}
