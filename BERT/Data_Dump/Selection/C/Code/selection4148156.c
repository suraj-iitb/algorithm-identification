#include<stdio.h>
#define N 100

int selectionSort(int *, int);

int main(){
  int i, n, A[N], count;

  scanf("%d", &n);
  for(i=0; i<n; i++) scanf("%d", &A[i]);

  count = selectionSort(A, n);

  for(i=0; i<n; i++){
    printf("%d", A[i]);
    if(i == n-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n", count);

  return 0;
}

int selectionSort(int *A, int n){
  int i, j, minj, a, count=0;

  for(i=0; i<n; i++){
    minj = i;
    for(j=i; j<n; j++){
      if(A[j] < A[minj]) minj = j;
    }

    if(A[i] != A[minj]){
      a = A[i];
      A[i] = A[minj];
      A[minj] = a;
      count++;
    }
  }

  return count;
}

