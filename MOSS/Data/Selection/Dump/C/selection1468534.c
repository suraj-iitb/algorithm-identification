#include <stdio.h>
#define N 100
#define exch(a, b) {int x = a; a = b; b = x; count++;}
#define less(a, b) (a < b)

void printarr(int *a, int n){
  int i;
  for(i = 0; i < n; i++){
    printf("%d", a[i]);
    printf((i == n - 1) ? "" : " ");
  }
  printf("\n");
}

int selectionSort(int *a, int n){
  int i, j, min, count = 0;
  for(i = 0; i < n - 1; i++){
    min = i;
    for(j = i + 1; j < n; j++)
      if(less(a[j], a[min])) min = j;
    if(min != i) exch(a[i], a[min]);
  }
  return count;
}

int main(void){
  int n, i, a[N], count;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);
  count = selectionSort(a, n);
  printarr(a, n);
  printf("%d\n", count);
  return 0;
}
