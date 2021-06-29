#include<stdio.h>

int main(){
  int A[110], n, i, j, t, temp = 0, min;

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);

  for ( i = 0; i < n; i++ ){
    min= i;
    for ( j = i; j < n; j++ ){
      if ( A[j] < A[min] ) min = j;
    }
    t = A[i]; A[i] = A[min]; A[min] = t;
    if ( i != min ) temp++;
  }

  for ( i = 0; i < n; i++ ){
    if (i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", temp);

  return 0;
}

