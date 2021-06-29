#include<stdio.h>
#include<stdlib.h>

int main() {
  int n, i, j, c[10000] = {}, max = 0;
  scanf("%d", &n);
  int a[n], x[n];

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
    if(max < a[i]) max = a[i];
    c[a[i]]++;
  }

  for(i = 1; i <= max; i++){
    c[i] += c[i-1];
  }

  for(j = n-1; j >= 0; j--){
    x[c[a[j]]-1] = a[j];
    c[a[j]]--;
  }

  for(i = 0; i < n; i++){
    printf("%d", x[i]);
    if(i != n-1) printf(" ");
  }

  printf("\n");

  return 0;
}

