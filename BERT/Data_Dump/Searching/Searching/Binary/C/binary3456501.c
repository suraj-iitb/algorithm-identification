#include <stdio.h>

int binarysearch(int a[], int n, int key) {
  int r = 0;
  int l = n;
  int i;
  while (l - r >= 1) {
    i = (r + l) / 2;
    if (a[i] == key)
      return 1;
    else if (a[i] < key) 
      r = i + 1;
    else
      l = i;
  }
  return 0;
}

int main()
{
  int n, q;
  int s[100000];
  int t[50000];
  int sum = 0;

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &s[i]);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &t[i]);
    if (binarysearch(s, n, t[i]))
      sum++;
  }
  printf("%d\n", sum);

  return 0;
}

