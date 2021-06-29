
#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main(){

  int *A, i, j, n, flag, count=0;

  scanf("%d",&n);

  A = (int *)malloc( sizeof(int) * n);

  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }

  flag = 1;

  while(flag){
    flag = 0;
    for(j=0; j<n-1; j++){
      for(i=n-1; i>0; i--){
	if(A[i] < A[i-1]){
	  swap(&A[i], &A[i-1]);
	  flag = 1;
	  count++;
	}
      }
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
