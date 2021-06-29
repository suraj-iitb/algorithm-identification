#include <stdio.h>
#include <stdlib.h>
#define K 10001

int main(){
  int *a, *b, c[K];
  int n, i;

  scanf("%d", &n);
  a = (int *)malloc(sizeof(int) * n);
  if( a == NULL ){
    printf("An error has occurred.\n");
    return -1;
  }
  b = (int *)malloc(sizeof(int) * n);
  if( a == NULL ){
    printf("An error has occurred.\n");
    return -1;
  }
  for(i = 0; i < n; i++) scanf("%d", &a[i]);

  for(i = 0; i < K; i++) c[i] = 0;

  for(i = 0; i < n; i++) c[ a[i] ]++;

  for(i = 1; i < K; i++) c[i] = c[i] + c[i - 1];

  for(i = n - 1; i > -1; i--){
    b[ c[ a[i] ] - 1] = a[i];
    c[ a[i] ]--;
  }

  for(i = 0; i < n - 1; i++) printf("%d ", b[i]); 
  printf("%d\n", b[n - 1]);

  free(a);
  free(b);

  return 0;
}
