#include <stdio.h>
#define N 100
#define exch(a, b) {int x = a; a = b; b = x;}
#define less(a, b) (a < b)
#define compexch(a, b) {if(less(a, b)){exch(a, b);count++;}}

void printarr(int *a, int n){
  int i;
  for(i = 0; i < n; i++){
    printf("%d", a[i]);
    printf((i == n - 1) ? "" : " ");
  }
  printf("\n");
}

int bubblesort(int *a, int n){
  int i, j, count = 0;
  for(i = 0; i < n - 1; i++)
    for(j = n - 1; j >= i; j--){
      compexch(a[j], a[j - 1]);
    }
    return count;
}

int main(void){
  int n, i, a[N], count;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);
  count = bubblesort(a, n);
  printarr(a, n);
  printf("%d\n", count);
  return 0;
}
