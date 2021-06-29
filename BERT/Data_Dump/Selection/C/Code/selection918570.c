#include<stdio.h>
static const int N = 100;
void selectionSort(int [], int);
void swap(int *, int *);

main() {
  int i, n, A[N];
  
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  selectionSort(A, n);
  return 0;
}

void selectionSort(int A[], int n){
  int i, j, mini, count = 0;

  for(i = 0; i < n; i++){
    mini = i;
    for(j = i; j < n; j++){
      if(A[j] < A[mini]) mini = j;
    }
    if(i != mini){
      swap(&A[i], &A[mini]);
      count++;
    }
  }

  for(i = 0; i < n; i++){
    printf("%d", A[i]);
    if(i != n - 1)printf(" ");
  }
  printf("\n%d\n", count);
}

void swap(int *p, int *q){
  int swap;
  swap = *p;
  *p = *q;
  *q = swap;
}
