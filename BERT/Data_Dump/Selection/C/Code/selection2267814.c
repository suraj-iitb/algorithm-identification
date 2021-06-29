#include <stdio.h>

int main(){
  int i, j, n, m, min;
  int count = 0;
  int A[100];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
      scanf("%d", &A[i]);
  }

  for(i = 0; i < n; i++){
    min = i;
    for(j = i; j < n; j++){
      if(A[j] < A[min]){
          min = j;
      }
    }

    if(i != min){
      m = A[i];
      A[i] = A[min];
      A[min] = m;
      count++;
    }
  }

  for(i = 0; i < n; i++){
    if(i>0){
        printf(" ");
    }
    printf("%d", A[i]);
  }
  printf("\n%d\n", count);

  return 0;
}
