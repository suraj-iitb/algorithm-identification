#include <stdio.h>
#include <stdlib.h>

int main(){
  int *a, b, i, j, n, minj, count = 0;

  scanf("%d", &n);

  a = (int *)malloc(n * sizeof(int));

  for(i = 0; i < n; i++) scanf("%d", &a[i]);

  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(a[j] < a[minj]) minj = j;
    }
    if(minj != i){
      b = a[i];
      a[i] = a[minj];
      a[minj] = b;
      count++;
    }
  }

  for(i = 0; i < n; i++){
    printf("%d", a[i]);
    if(i < n-1) printf(" ");
  }

  printf("\n%d\n", count);

  free(a);

  return 0;
}

