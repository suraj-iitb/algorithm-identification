#include <stdio.h>
#define N 2000002
#define MAX 10000

int A[N],B[N];
int main(){

  int C[MAX+1];
  int v, i, j;

  for ( i = 0; i <= MAX; i++ ) C[i] = 0;

  scanf("%d", &v);

  for ( i = 0; i < v; i++ ){
    scanf("%d", &A[i + 1]);
    C[A[i + 1]]++;
  }


  for ( i = 1; i <= MAX; i++ ) C[i] = C[i] + C[i - 1];

  for ( j = 1; j <= v; j++ ){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

    for ( i = 1; i <v; i++ ){
    printf("%d ", B[i]);
  }
  printf("%d",B[i]);
  printf("\n");

  return 0;
}


