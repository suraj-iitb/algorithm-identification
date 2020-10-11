//Selection Sort

#include <stdio.h>
#include <stdlib.h>

main(){
  
  int n;
  int *a; //配列用ポインタ
  int minj;
  int c; //交換回数

  int i,j,tmp;

  scanf("%d", &n);

  a = (int *)malloc(sizeof( int ) * n);

  for( i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }

  c = 0;

  for( i=0; i<n; i++) {
    minj = i;
    for( j=i; j<n; j++) {
      if( a[j] < a[minj] ) {
	minj = j;
      }
    }
    if(a[i] != a[minj]) {
      tmp = a[i];
      a[i] = a[minj];
      a[minj] = tmp;
      c++;
    }
  }
  
  
  for( i=0; i<n-1; i++) { 
    printf("%d ", a[i]);
  }
  printf("%d\n%d\n", a[n-1], c);
  
  free(a);
  
  return 0;
  
}
