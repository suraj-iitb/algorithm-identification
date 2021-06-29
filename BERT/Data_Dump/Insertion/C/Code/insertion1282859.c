#include <stdio.h>

#define MAXLENGTH 1000 //配列の最大の長さ

main() {
  
  int i,j, v, p;
  int N; //配列の長さ
  int A[MAXLENGTH]; //配列
  
  scanf(" %d", &N);
  
  for( i=0; i<N; i++) {
    scanf(" %d", &A[i]);
  }
  
  for( i=1; i<N; i++) {

    printf("%d", A[0]);
    for( p=1; p<N; p++) {
      printf(" %d", A[p]);
    }
    printf("\n");

    v = A[i];
    j = i-1;
    while( j>=0 && A[j]>v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;

  }

  printf("%d", A[0]);
  for( p=1; p<N; p++) {
    printf(" %d", A[p]);
  }
  printf("\n");
  
  return 0;
}
