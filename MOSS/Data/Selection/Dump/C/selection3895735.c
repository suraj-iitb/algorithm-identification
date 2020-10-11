#include<stdio.h>

void selectionsort(int A[], int n);
int count;

int main(){
  int n, k;
  int A[100];

  scanf("%d", &n);
  for(k = 0; k < n; k++){
    if(k == n-1){
      scanf("%d", &A[k]);
    }else{
      scanf("%d ", &A[k]);
    }
  }

  count = 0;
  selectionsort(A, n);

  for(k = 0; k < n; k++){
    if(k == n-1){
      printf("%d\n", A[k]);
    }else{
      printf("%d ", A[k]);
    }
  }

  printf("%d\n", count);

  return 0;
}

void selectionsort(int A[], int n){
  int i, j;
  int min, tmp;

  for(i = 0; i < n; i++){
    min = i;
    for(j = i; j < n; j++){
      if(A[j] < A[min]){
        min = j;
      }
    }
    if(A[i] != A[min]){
      tmp = A[i];
      A[i] = A[min];
      A[min] = tmp;
      count++;
    }
  }
}

