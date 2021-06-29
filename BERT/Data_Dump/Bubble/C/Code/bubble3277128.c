#include <stdio.h>

void swap(int *, int *);

int main(){
  int i,j,n,count = 0;
  int A[100];

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; i < n-1; i++){
    for(j = n-1; j > i; j--){
      if(A[j] < A[j-1]){
	swap(&A[j],&A[j-1]);
	count++;
      }
    }
  }

  for(i = 0; i < n; i++){
    printf("%d",A[i]);
    if(i != n-1) printf(" ");
  }

  printf("\n%d\n",count);

  return 0;

}

void swap(int *x, int *y){
  int p;

  p = *x;
  *x = *y;
  *y = p;
}

