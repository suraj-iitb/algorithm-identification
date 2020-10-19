#include <stdio.h>
#include <stdlib.h>
#define N 2000000
#define A 10000

int main(){
  int *a, *b, c[A], n, i;

  scanf("%d", &n);

  a = (int *)malloc(sizeof(int) * n);
  b = (int *)malloc(sizeof(int) * n);
  for(i = 0; i < A; i++)
    c[i] = 0;

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
    c[a[i]]++;
  }

  for(i = 1; i < A; i++)
    c[i] += c[i - 1];

  for(i = n - 1; i >= 0; i--){
    b[c[a[i]] - 1] = a[i];
    c[a[i]]--;
  }
  
  for(i = 0; i < n - 1; i++){
    printf("%d ", b[i]);
  }
  printf("%d\n", b[i]);

  free(a);
  free(b);

  return 0;
}