#include<stdio.h>

static const int N = 100;
void bubbleSort(int [], int);
void swap(int *, int *);

main(){
  int i, n;
  int A[N + 1];
  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  bubbleSort(A, n);
  return 0;
}

void bubbleSort(int A[], int n){
  int i, j, count = 0;
  
  for(i = 0; i < n; i++){
    for(j = n - 1; j > i; j--){
      if (A[j] < A[j - 1]){
	swap(&A[j], &A[j - 1]);
	count++;
      }
    }
  }
  
  for(i = 0; i < n; i++){
    printf("%d", A[i]);
    if(i != n - 1) printf(" ");
  }
  
  printf("\n");
  printf("%d\n", count);
}

void swap(int *p, int *q){
  int swap;
  swap = *p;
  *p = *q;
  *q = swap;
}
