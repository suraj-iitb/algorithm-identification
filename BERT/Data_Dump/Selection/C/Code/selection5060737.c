#include<stdio.h>
#include<stdlib.h>


int selectionsort(int *,int);  /*戻値は交換回数*/

int main(){
  int *A, n, i, k;

  scanf("%d",&n);


  A = malloc(sizeof(int) * n);

  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }

  k = selectionsort(A,n);

  for(i = 0 ; i < n ; i++){
    if(i != 0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",k);

  return 0;
}

int selectionsort(int *A, int n){
  int i, j, minj, d, t= 0;

  for(i = 0 ; i < n ; i++){
    minj = i;
    for(j = i ; j < n ; j++){
      if(A[j] < A[minj])minj = j;
    }
    d = A[i];
    A[i] = A[minj];
    A[minj] = d;
    if(minj != i) t++;
  }

  return t;
}
	
  
	   


