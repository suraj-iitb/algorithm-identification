#include<stdio.h>
#include<stdlib.h>

int selectionSort(int [], int);

int main(){
  int n, cnt;
  int *A;
  int i;

  scanf("%d",&n);

  A = (int *)malloc(n*sizeof(int));

  for(i=0; i<n; i++)
    scanf("%d",&A[i]);
  
  cnt = selectionSort(A,n);

  for(i=0; i<n; i++){
    printf("%d",A[i]);
    if(i<n-1)
      printf(" ");
  }
  printf("\n%d\n",cnt);
  
  free(A);
  return 0;
}

int selectionSort(int A[],int n){
  int minj, tmp, cnt=0;
  int i, j;

  for(i=0; i<n; i++){
    minj = i;
    
    for(j=i; j<n; j++){
      if(A[j] < A[minj])
	minj = j;
    }

    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;

    if(i!=minj)
      cnt++;
  }
  
  return cnt;
}

