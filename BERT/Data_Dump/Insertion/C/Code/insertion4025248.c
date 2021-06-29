#include <stdio.h>

void insertionSort(int *, int);

int main(){
  int A[1000], N, i;

  scanf("%d",&N);

  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }
  printf("%d",A[0]);
  for(i = 1; i < N; i++){
    printf(" %d",A[i]);
  }
  printf("\n");
  insertionSort(A, N);

  return 0;
}

void insertionSort(int *a, int n){
  int i, j, k, key;

  for(j = 1; j < n; j++){
    key = *(a + j);
    i = j - 1;
    while(i >= 0 && *(a + i) > key){
      *(a + (i+1)) = *(a + i);
      i = i - 1;
    }
    *(a + (i+1)) = key;
    printf("%d",*a);
    for(k = 1; k < n; k++) printf(" %d",*(a+k));
    printf("\n");
  }

  return;
}

