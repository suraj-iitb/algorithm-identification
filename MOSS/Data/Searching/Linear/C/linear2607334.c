#include<stdio.h>

int Linear(int a[], int n, int key){
  int i = 0;
  a[n]  = key;
  while (a[i] != key)
    i++;
  if (i==n){
    return 0;
  } else {
    return 1;
  }
}

int main(){
  int i, n, a[10001], q, key;
  int sum = 0;

  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &a[i]);

  scanf("%d", &q);
  for (i=0; i<q; i++) {
    scanf("%d", &key);
    if (Linear(a, n, key)==1)
      sum++;
  }
  printf("%d\n", sum);

  return 0;
}
