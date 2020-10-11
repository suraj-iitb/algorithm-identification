#include <stdio.h>
#include <stdlib.h>
#define N 2000000
#define A 10000

int c[A];

int main(){

  int i;
  int *a, *b;
  int n, tmp;

  scanf("%d",&n);

  a = (int *)malloc(sizeof(int) * n);
  b = (int *)malloc(sizeof(int) * n);

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
    c[a[i]]++;
  }

  tmp = c[0];
  for(i = 1; i < A; i++){
    c[i] += c[i - 1];
  }

  for(i = n - 1; i >= 0; i--){
    b[c[a[i]] - 1] = a[i];
    c[a[i]]--;
  }

  for(i = 0; i < n; i++){
    printf("%d", b[i]);
    if(i < n - 1) printf(" ");
  }

  printf("\n");


  free(a);
  free(b);

  return 0;
}
