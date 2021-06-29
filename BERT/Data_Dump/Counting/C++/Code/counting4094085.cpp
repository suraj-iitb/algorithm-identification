#include <stdio.h>
#include <cstdlib>
#define MAX 2000001
#define VMAX 10000

void CountingSort(int *, int *, int);

int n;

int main(){
  int *A, *B;
  int i, max = 0;

  scanf("%d", &n);

  A = (int *)malloc(sizeof(int)*n+1);
  B = (int *)malloc(sizeof(int)*n+1);

  /* your code */
  for(i = 1; i < n+1; i++){
    scanf("%d", &A[i]);
    if(max < A[i]){
      max = A[i];
    }
    //printf("max:%d\n",max);
  }
  
  CountingSort(A, B, max);
  for(i = 1; i < n; i++){
    printf("%d ", B[i]);
  }
  printf("%d\n", B[n]);



  return 0;
}


void CountingSort(int *A, int *B, int k){
  int i, j;
  int C[VMAX+1];
 
  for(i = 0; i <= k; i++){
    C[i] = 0;
  }
  
  // Put the number of each A[i] into C[A[i]]
  for(j = 1; j <= n; j++){
    C[A[j]]++;
    //printf("C[%d]:%d\n", A[j], C[A[j]]);
  }
  //printf("\n");
  
  // C to C'
  for(i = 1; i <= k; i++){
    C[i] += C[i-1];
    //printf("C[%d]:%d\n", i, C[i]);
  }
  
  for(j = n; j > 0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
















