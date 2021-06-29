#include <stdio.h>
void insertionSort(int *, int );
void print(int *, int );

int main(){
  int A[100],N=0,i,j;
  
  scanf("%d",&N);
  for( i = 0; i < N; i++ ){
    scanf("%d",&A[i]);
  }
  print(A,N);
  insertionSort(A, N);

  return 0; 
}

void insertionSort(int *A, int N){
  int v=0,j=0,i;
  for( i = 1; i < N; i++ ){
    v = A[i];
    j = i - 1;
    while( j >= 0 && A[j] > v ){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    print(A,N);
  }
}

void print(int *A, int N){
  int i;
  for(i = 0; i < N-1; i++){
    printf("%d ",A[i]);
  }
  if(i==N-1){
    printf("%d",A[i]);
  }
  printf("\n");
}

