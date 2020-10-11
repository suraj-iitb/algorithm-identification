#include<stdio.h>
#define K 10000

void countingSort(int a[], int b[], int k, int n){
  int c[k+1];
  int i;
  for(i = 0; i <= k; i++)
    c[i] = 0;

  for(i = 1; i <= n; i++)
    c[a[i]]++;

  for(i = 1; i <= k; i++)
    c[i] = c[i] + c[i-1];

  for(i = n; i >= 1; i--){
    b[c[a[i]]] = a[i];
    c[a[i]]--;
  }
}

void trace(int a[], int n){
  int i;
  for(i = 1; i < n; i++)
    printf("%d ", a[i]);
  printf("%d\n", a[i]);
}

int main(void){
  int n = 0;
  scanf("%d", &n);
  int i;
  int a[n+1];
  int b[n+1];

  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  countingSort(a, b, K, n);
  trace(b, n);

  return 0;
}
