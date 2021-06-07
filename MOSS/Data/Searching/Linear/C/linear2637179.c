#include <stdio.h>
#include <stdlib.h>

int linearSearch(int a[], int n, int key){
  int i;
  for(i = 0; i < n; i++){
    if(a[i] == key){
      return 1;
    }
  }
  return 0;
}

int main(void){
  int n, i, q, c = 0;
  int *a;
  int *b;

  scanf("%d", &n);
  a = (int *)malloc(n * sizeof(int));
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  scanf("%d", &q);
  b = (int *)malloc(q * sizeof(int));
  for(i = 0; i < q; i++){
    scanf("%d", &b[i]);
  }

  for(i = 0; i < q; i++){
    c += linearSearch(a, n, b[i]);
  }

  printf("%d\n", c);
  
  return 0;
}
