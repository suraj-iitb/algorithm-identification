#include<stdio.h>

int main(){

  int i,j,k,minj,a,A[100],count = 0;

  scanf("%d",&a);

  for(i = 0; i < a; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; i < a; i++){

    minj = i;

    for(j = i; j < a; j++){
      if(A[j] < A[minj]) {
	minj = j;
      }
    }
    if(minj != i) count++;
    k = A[i];
    A[i] = A[minj];
    A[minj] = k;
  }

  for(i = 0; i < a; i++){
    printf("%d",A[i]);
    if(i == a -1) break;
    printf(" ");
  }

  printf("\n");

  printf("%d\n",count);

  return 0;
}
