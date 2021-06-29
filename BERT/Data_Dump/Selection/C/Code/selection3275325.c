#include<stdio.h>

static const int N = 100;

int selectionSort(int A[], int n){
  int i, j, temp, count = 0;
  int min_j;
  for(i = 0; i < n-1 ; i++){
    min_j = i;
    for( j = i ; j < n ; j++){
      if(A[j] < A[min_j]) min_j = j;
    }
    temp = A[i];
    A[i] = A[min_j];
    A[min_j] = temp;
    if(i != min_j) count++;
  }
  return count;
}

int main(){
  int i, n, count;
  int A[N+1];
  scanf("%d", &n);
  for( i = 0 ; i < n; i++){
    scanf("%d", &A[i]);
  }

  count = selectionSort(A, n);

  for(i = 0 ; i < n ; i++){
    if(i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n",count);
}
