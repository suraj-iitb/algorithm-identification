#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linearSearch(int a[], int n, int key)
{
  int i = 0;
  a[n] = key;

  for(i = 0; i < n; i++){
    if(a[i] == key)  return 1;
  }
  return 0;
}

int main(void)
{
  int a[10000], i, j, n, q, key, result = 0;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  scanf("%d", &q);

  for(j = 0; j < q; j++){
    scanf("%d", &key);
    if(linearSearch(a, n, key)){
      result++;
    }
  }
  printf("%d\n", result);

  return 0;
}

