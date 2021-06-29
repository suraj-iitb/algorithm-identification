#include <stdio.h>
 
int N = 100;
 
void out(int A[], int n){
  int i;
  for (i=0;i<n;i++){
    if (i>0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void intertionSort(int* A, int n){
  int i, j, key=0;
  for(i = 0; i < n; i++){
    key = A[i];
    j = i-1;
    while(j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    out(A,n);
  }
}
 
int main(void){
  int n, i;
  int A[N+1];
  scanf("%d", &n);
 
  for (i=0;i<n;i++) scanf("%d", &A[i]); //data input
  intertionSort(A, n);
 
  return 0;
}
