#include <stdio.h>

int *insertionSort(int *, int);

void printArray(int *, int );
int main() {
  
  int n,a[1000],*b;
  int i;

  for (i = 0; i < 1000; i++ ) {
        a[i] = 0;
    }

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  b = insertionSort(a,n);
  
  printArray(b,n);
  printf("\n");
  return 0;
}

int *insertionSort (int *A, int N) {
  int i,j;
  int v;
  
  for(i = 1 ; i < N ; i++ ) { 
    printArray(A,N);
    printf("\n");

    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

  }
  return A;
}

void printArray(int *A, int N) {
  int i;
  
  for(i=0;i<N-1;i++) {
    printf("%d ",A[i]);
  }
  printf("%d",A[N-1]);
}
