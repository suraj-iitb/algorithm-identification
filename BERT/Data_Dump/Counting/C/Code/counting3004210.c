#include <stdio.h>
#include <stdlib.h>
void CountingSort(int);
#define MAX 2000001
#define VMAX 10000
int C[VMAX+1];
unsigned short *A, *B;
int main(){
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=0;i < n;i++){
    scanf("%hd",&A[i]);
  }
  CountingSort(n);
  for(i = 1; i < n+1; i++){
    if(i>1) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");

  return 0;
}


void CountingSort(k){
  int i,j;
  for(i = 0 ;i <= VMAX;i++){
    C[i] = 0;
      }
  /* C[i] に i の出現数を記録する */
  for(j = 0; j < k; j++){
    C[A[j]]++;
      }
  /* C[i] に i 以下の数の出現数を記録する*/
  for (i = 1; i < VMAX; i++){
    C[i] = C[i] + C[i-1];
      }
  for(j = k-1 ; j >= 0; j--){
    B[C[A[j]]] = A[j];
      C[A[j]]--;
      }

}

