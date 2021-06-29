#include<stdio.h>

void selectionSort(int);

int main(){
  int n;

  scanf("%d",&n);

  selectionSort(n);

  return 0;
}

void selectionSort(int n){
  int A[n], i, j, minj, v, count = 0;

  for(i = 0; i < n; i++)
    scanf("%d",&A[i]);
  
  for(i = 0; i <= n - 1; i++){
    minj = i;
    for(j = i; j <= n - 1; j++){
      if(A[j] < A[minj])
	minj = j;
    }
    
    v = A[i];
    A[i] = A[minj];
    A[minj] = v;
    if(A[i] != A[minj]){
      count++;
    }
  }
  for(i = 0; i < n; i++){
    printf("%d",A[i]);
    if(i != n - 1)
      printf(" ");
  }
  printf("\n%d\n",count);
}
