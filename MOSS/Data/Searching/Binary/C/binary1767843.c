#include <stdio.h>
#include <stdlib.h>

int binarysearch(int *, int, int);

int main()
{
  int n, q, i, count = 0;
  int *s, *t;

  scanf("%d", &n);
  s = (int *)malloc(n*sizeof(int));
  for(i=0; i<n; i++) {
    scanf("%d", &s[i]);
  }
  scanf("%d", &q);
  t = (int *)malloc(q*sizeof(int));
  for(i=0; i<q; i++) {
    scanf("%d", &t[i]);
  }

  for(i=0; i<q; i++) {
    if(binarysearch(s, n, t[i]))
      count++;
  }
  printf("%d\n", count);
  return 0;
}

int binarysearch(int *s, int n, int key)
{
  int mid, left = 0, right = n;

  while(left < right) {
    mid = (left + right)/2;
    if(s[mid] == key)
      return 1;
    else if(key < s[mid])
      right = mid;
    else
      left = mid + 1;
  }
  return 0;
}
