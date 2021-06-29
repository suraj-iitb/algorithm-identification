#include <stdio.h>


int main(){

  int i, j, n, k;
  k = 0;

  scanf("%d", &n);

  //1 origin
  int *a;
  int *b;
  a = malloc(sizeof(int) * (n+1));
  b = malloc(sizeof(int) * (n+1));

  for(i = 1; i < n+1; i++){
    scanf("%d", &a[i]);
    if(k < a[i])
      k = a[i];
  }

  int c[k+1];
  for(i = 0; i < k+1; i++)
    c[i] = 0;

  for(j = 1; j < n+1; j++)
    c[ a[j] ]++;

  for(i = 1; i < k+1; i++)
    c[i] = c[i] + c[i-1];

  for(j = n; j > 0; j--){
    b[ c[ a[j] ] ] = a[j];
    c[ a[j] ]--;
  }

  for(i = 1; i < n; i++)
    printf("%d ", b[i]);
  printf("%d\n", b[i]);

  free(a);
  free(b);

  return 0;
}
