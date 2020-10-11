#include <stdio.h>
#include <stdlib.h>

void selectionSort(int A[], int N){
  int i, minj, j, t, c = 0;
  for(i = 0; i < N; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(i != minj){
      t = A[i];
      A[i] = A[minj];
      A[minj] = t;
      c++;
    }
  }
  for(i = 0; i < N; i++){
    printf("%d",A[i]);
    if(i <= N-2) printf(" ");
  }
  printf("\n%d\n", c);
}


int main(void){
  int i, n;
  scanf("%d", &n);
  int *a;
  a = malloc(n * sizeof(int));
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  selectionSort(a, n);
  return 0;
}
