#include<stdio.h>

int Binary(int a[], int key, int n){
  int left  = 0;
  int right = n;
  int mid;

  while (left < right) {
    mid = (right + left) /2;
    if (key == a[mid])
      return 1;
    if (key > a[mid]) {
      left = mid+1;
    } else if (key < a[mid]) {
      right = mid;
    }
  }
  return 0;
}

int main(){
  int i, q, key, a[1000000], n;
  int sum = 0;

  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &a[i]);

  scanf("%d", &q);
  for (i=0; i<q; i++) {
    scanf("%d", &key);
    if (Binary(a, key, n)==1)
      sum++;
  }

  printf("%d\n", sum);
  return 0;
}
