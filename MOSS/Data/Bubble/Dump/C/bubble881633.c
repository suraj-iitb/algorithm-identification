#include <stdio.h>

void swap(int *x, int *y){int t = *x; *x = *y; *y = t;}

int main(){
  int n, a[101], i, j, c = 0;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) scanf("%d", a + i);

  for(i = 0; i < n; ++i)
    for(j = n - 1; j > i; --j)
      if(a[j] < a[j - 1]){
        swap(&a[j], &a[j - 1]);
        c++;
      }

  for(i = 0; i < n; ++i) printf(i != 0 ? " %d": "%d", a[i]);
  printf("\n%d\n", c);
  return 0;
}
