#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

void CountingSort(short *,short *,int);

int n;

int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i = 1; i <= n; i++){
    scanf("%d",&A[i]);
  }

  CountingSort(A,B,VMAX);

  return 0;
}

void CountingSort(short *A,short *B,int k){
  int i,j;
  int C[k+1];
  
  for(i = 1; i <= k;i++){
    C[i] = 0;
  }

  for(j = 1; j <= n;j++){
    C[A[j]]++;
  }

  for(i = 1; i <= k;i++){
    C[i] = C[i] + C[i-1];
  }

  for(j = n; j >= 1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i = 1; i <= n; i++){
    printf("%d",B[i]);
    if(i != n)printf(" ");
    else printf("\n");
  }

  return;
}

