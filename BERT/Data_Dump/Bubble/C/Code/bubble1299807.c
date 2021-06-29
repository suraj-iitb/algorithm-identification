//Bubble Sort

#include <stdio.h>
#include <stdlib.h>

main(){
  
  int n;
  int *a; //配列用ポインタ
  int c; //交換回数

  int i,j,tmp;

  scanf("%d", &n);

  a = (int *)malloc(sizeof( int ) * n);

  for( i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }

  c = 0;

  for( i=0; i<n; i++) {
    for( j=n-1; j>i; j--) {
      if( a[j] < a[j-1] ) {
	tmp = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp;
	c++;
      }
    }
  }

  for( i=0; i<n-1; i++) { 
    printf("%d ", a[i]);
  }
  printf("%d\n%d\n", a[n-1], c);

  free(a);

  return 0;

}
