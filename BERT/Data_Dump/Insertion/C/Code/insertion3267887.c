#include <stdio.h>

int main () {
  int n = 0, A[100], i, j, key = 0;

  for(i = 0 ; i < 100 ; i++) A[i] = 0;

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++) {
    scanf("%d",&A[i]);
  }

  for(i = 0 ; i < n ; i++) {
    if(i == n - 1) printf("%d",A[i]);
    else printf("%d ",A[i]);
  }
  printf("\n");

  for(i = 1 ; i <= n - 1 ; i++) {
    key = A[i];
    j = i - 1;

    while(j >= 0 && A[j] > key) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;

    for(j = 0 ; j < n ; j++) {
      if(j == n - 1) printf("%d",A[j]);
      else printf("%d ",A[j]);
    }
    printf("\n");
  }
  

  return 0;
}

