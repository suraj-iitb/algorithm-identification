#include <stdio.h>

void swap(int *x, int *y){ int t = *x; *x = *y; *y = t;}

int main(){
  int n, a[101], min, i, j, c = 0;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) scanf("%d", a + i);

  for(i = 0; i < n; ++i){
    min = i;
    for(j = i + 1; j < n; ++j)
      if(a[j] < a[min]) min = j;
    if(min != i){
      swap(&a[i], &a[min]);
      c++;
    }
  }

  for(i = 0; i < n; ++i) printf(i != 0 ? " %d" : "%d", a[i]);
  printf("\n%d\n", c);
  return 0;
}
