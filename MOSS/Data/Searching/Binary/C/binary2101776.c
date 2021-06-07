#include <stdio.h>

int search(int key, int n, int array[])
{
  int left, right, mid;
  left = 0;
  right = n;
  while (left < right) {
    mid = (left + right) / 2;
    if (array[mid] == key)     return 1;
    else if (array[mid] > key) right = mid;
    else                       left = mid + 1;
  }
  return 0;
}

int main(void)
{
  int n, s[100000];
  int q, t[50000];
  int i, count = 0;

  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &s[i]);
  scanf("%d", &q);
  for (i = 0; i < q; i++) scanf("%d", &t[i]);

  for (i = 0; i < q; i++) {
    if (search(t[i], n, s)) count++;
  }
  printf("%d\n", count);

  return 0;
}
