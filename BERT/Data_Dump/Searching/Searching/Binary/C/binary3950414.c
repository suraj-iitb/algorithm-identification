#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, a[100000];

int binarySearch(int key)
{
  int mid, left = 0, right;

  right = n;

  while(left < right){
    mid = (left + right) / 2;
    if(key == a[mid]) return 1;
    else if(key > a[mid]) left = mid + 1;
    else if(key < a[mid]) right = mid;
  }
  return 0;
}

int main(void)
{
  int i, j, q, key, result = 0;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  scanf("%d", &q);

  for(j = 0; j < q; j++){
    scanf("%d", &key);
    if(binarySearch(key)){
      result++;
    }
  }
  printf("%d\n", result);

  return 0;
}

