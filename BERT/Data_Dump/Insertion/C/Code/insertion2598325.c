#include<stdio.h>

void Printfff(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    printf("%d", A[i]);
    if ( i < n-1 ) printf(" ");
  } 
  printf("\n");
}

void insertionSort(int A[], int n){
  int v, i, j;
  for ( i = 1; i < n; i++ ) {
    v = A[i];
    j = i - 1;
    while ( j >= 0 && A[j] > v ){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  Printfff(A, n);
  }
}

int main(){

  int n, i;
  int A[100];

  scanf("%d", &n);
  for ( i = 0; i < n; i++) scanf("%d", &A[i]);

  Printfff(A, n);
  insertionSort(A, n);


  return 0;
}
  
