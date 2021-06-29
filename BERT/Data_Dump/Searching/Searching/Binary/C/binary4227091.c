#include <stdio.h>

int binarysearch(int a[], int key, int n)
{
  int left = 0, right = n, mid;
  
  while (left < right) {
    mid = (left + right) / 2;
    if (a[mid] == key)
      return 1;
    if (a[mid] > key)
      right = mid;
    else
      left = mid + 1;
  }
  
  return 0;
}

int main(void)
{
  int n, q, t, cnt = 0;
  int s[1000000];
  
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++)
    scanf("%d", &s[i]);
  
  scanf("%d", &q);
  
  while(q--) {
    scanf("%d", &t);
    if (binarysearch(s, t, n))
      cnt++;
  }
  
  printf("%d\n", cnt);
  
  return 0;
}
