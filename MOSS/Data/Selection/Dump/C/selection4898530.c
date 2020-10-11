#include<stdio.h>
int main(){
  int A[101], n, i, j, t, sw = 0, mini;

  scanf("%d", &n);
  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);

  for ( i = 1; i <= n; i++ ){
    mini = i;
    for ( j = i; j <= n; j++ ){
      if ( A[j] < A[mini] ) mini = j;
    }
    t = A[i]; A[i] = A[mini]; A[mini] = t;
    if ( i != mini ) sw++;
  }

  for ( i = 1; i <= n; i++ ){
    if (i>1) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", sw);

  return 0;
}

