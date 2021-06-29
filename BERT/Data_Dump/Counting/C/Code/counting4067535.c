#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  int n = 0;
  unsigned short *A, *B;
  int C[VMAX+1];
  int i = 0, j = 0;

  scanf("%d",&n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
  
  for(i = 0; i < n; i++){
    scanf("%hu",&A[i+1]);
  }

  /*CountingSort*/
  for(i = 0; i <= VMAX; i++){
    C[i] = 0;
  }

  /*C[i]にiの出現回数を記録する*/
  for(j = 1; j <= n; j++){
    C[A[j]]++;
  }

  /*C[i]に以下の数の出現数を記録する*/
  for(i = 1; i <= VMAX; i++){
    C[i] = C[i] + C[i-1];
  }

  for(j = n; j > 0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  /*end of Sort*/
  
  for(i = 1; i <= n; i++){
    printf("%d",B[i]);
    if(i < n)printf(" ");
    else printf("\n");
  }
  return 0;
}
/*
void CountingSort(int *A, int *B, int k){
  int i = 0;
  int j = 0;
  int C[N];

  for(i = 0; i <= k; i++){
    C[i] = 0;
  }
*/
  /*C[i]にiの出現回数を記録する
  for(j = 1; j <= n; j++){
    C[A[j]]++;
  }
  */
  /*C[i]に以下の数の出現数を記録する
  for(i = 0; i <= k; i++){
    C[i] = C[i] + C[i-1];
  }
  */
/* for(j = n; j > 0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
*/

