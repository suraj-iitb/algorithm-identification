#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

void CountingSort(int *,int *,int);

int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);


  for(i = 1; i < n+1; i++){
    scanf("%d",&A[i]);
  }
  
  for(i = 0; i <= VMAX; i++){
    C[i] = 0;
  }

  for(j = 1; j < n+1; j++){
    C[A[j]]++;
  }

  for(i = 1; i < VMAX; i++){
    C[i] = C[i] + C[i-1];
  }

  for(j = n; j > 0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i = 1; i <= n; i++){
    if(i == n){
      printf("%d",B[i]);

    }else{
      printf("%d ",B[i]);
    }

  }

  printf("\n");

  return 0;
}





