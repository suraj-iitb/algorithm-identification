#include<stdio.h>


void selectionSort(void);

int A[100], n, count=0;

int main(){
  int i;

  scanf("%d", &n);

  for(i = 0; i < n; i++)
    scanf("%d", &A[i]);

  selectionSort();

  for(i = 0; i < n; i++){
    printf("%d", A[i]);
    if(i == n-1) break;
    printf(" ");
  }

  printf("\n%d\n", count);

  return 0;
}

void selectionSort(void){
  int i, j, a, minj;
  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(A[j] < A[minj])
	minj = j;
    }
    if(A[i] != A[minj]){
      a = A[i];
      A[i] = A[minj];
      A[minj] = a;
      count++;
    }
  }
}
