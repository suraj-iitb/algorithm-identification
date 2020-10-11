#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10000

void CountingSort(unsigned short *A, unsigned short *B, int C[], int n){
  int i;

  for(i = 0; i <= VMAX; i++) C[i] = 0;

  for(i = 0; i < n; i++){
    scanf("%hu", &A[i+1]);
    C[A[i+1]]++;
  }

  for(i = 1; i <= VMAX; i++){
    C[i] = C[i] + C[i-1];
  }

  for(i = 1; i <= n; i++){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
}

int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int n, i;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  CountingSort(A, B, C, n);

  printf("%d", B[1]);
  for(i = 2; i <= n; i++){
    printf(" %d", B[i]);
  }
  printf("\n");

  return 0;
}

