#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main(){

  int i, j, n, *A, minj, count=0;

  scanf("%d",&n);

  A = (int *)malloc(sizeof(int) * n);

  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }

  for(i=0; i<n-1; i++){
    minj = i;
    for(j=i; j<n; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    swap(&A[i], &A[minj]);
    if(A[i] != A[minj]){
      count++;
    }
  }

  for(i=0; i<n-1; i++){
    printf("%d ", A[i]);
  }

  printf("%d\n",A[i]);
  printf("%d\n",count); 

  return 0;
}

void swap(int *a, int *b){
  int c;

  c = *a;
  *a = *b;
  *b = c;

}
