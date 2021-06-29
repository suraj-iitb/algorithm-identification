#include <stdio.h>
#include <stdlib.h>

void swap(int *,int *);

int main() {
  int i, j, n, minj, cnt, *a;

  scanf("%d", &n);
  a = (int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) scanf("%d", &a[i]);

  cnt = 0;
  for(i=0;i<n;i++) {
    minj = i;
    for(j=i;j<n;j++) if(a[j] < a[minj]) minj = j;
    if(minj != i){
      swap(&a[i],&a[minj]);
      cnt++;
    }
  }

  for(i=0;i<n-1;i++) printf("%d ", a[i]);
  printf("%d\n", a[i]);
  printf("%d\n", cnt);
  
  free(a);
  return 0;
}

void swap(int *x, int *y) {
  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;

  return;
}

