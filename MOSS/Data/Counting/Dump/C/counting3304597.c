#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

void CountingSort(int *,int *,int);
void recordplus(int *,int *,int);
void recordplusunder(int *);

int main(){
  int *A,*B;
  int n,i;

  scanf("%d", &n);

  A = (int *)malloc(sizeof(int)*n+1);
  B = (int *)malloc(sizeof(int)*n+1);

  /* your code */

  for(i = 1;i <= n;i++){
    scanf("%d",&A[i]);
    B[i] = 0;
  }

  CountingSort(A,B,n);

  for(i = 1;i <= n;i++){
    printf("%d",B[i]);
    if(i != n) printf(" ");
  }
  printf("\n");

  free(A);
  free(B);
  return 0;
}

void CountingSort(int *A,int *B,int n){
  int i,C[VMAX+1];
  for(i = 0;i <= VMAX;i++) C[i] = 0;
  recordplus(A,C,n);
  recordplusunder(C);
  for(i = n;i != 0;i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
  
}

void recordplus(int *A,int *C,int n){
  int i;
  for(i = 1;i <= n;i++){
    C[A[i]]++;
  }
  
}

void recordplusunder(int *C){
  int i;
  for(i = 1;i < VMAX + 1;i++) C[i] = C[i] + C[i - 1];
}

