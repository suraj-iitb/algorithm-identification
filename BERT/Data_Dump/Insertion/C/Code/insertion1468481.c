#include <stdio.h>
#define N 100

void printarr(int *a, int n){
  int i;
  for(i = 0; i < n; i++){
    printf("%d", a[i]);
    printf((i == n - 1) ? "" : " ");
  }
  printf("\n");
}

void insertion(int *a, int n){
  int i, j, v;
  for(i = 1; i < n; i++){
    v = a[i];
    j = i;
    while(--j >= 0 && a[j] > v) a[j + 1] = a[j];
    a[++j] = v;
    printarr(a, n);
  }
}

int main(void){
  int a[N], n, i;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printarr(a, n);
  insertion(a, n);
  return 0;
}
