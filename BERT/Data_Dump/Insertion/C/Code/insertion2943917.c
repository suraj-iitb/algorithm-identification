#include<stdio.h>
void arraypPrint(int[], int);
void insertionSort(int[], int);
int main(){
  int N, i;
  int A[100];
  scanf("%d",&N);
  for( i = 0 ; i < N ; i++ ){
    scanf("%d",&A[i]);
  }

  arraypPrint(A, N);
  insertionSort(A, N);

  return 0;
}

void insertionSort(int A[], int N){
  int i, j, v;
  for( i = 1 ; i < N ; i++ ){
    v = A[i];
    j = i - 1;
    while( j >= 0 && A[j] > v ){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    arraypPrint(A, N);
  }
}

void arraypPrint(int A[], int N){
  int i;
  for( i = 0 ; i < N ; i++ ){
    if( i > 0 ) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

