#include <stdio.h>
#include <stdlib.h>

int linearsearch(int *, int, int);

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
    if(linearsearch(s, n, t[i]))
      count++;
  }
  printf("%d\n", count);
  return 0;
}

int linearsearch(int *s, int n, int key)
{
  int i = 0;
  s[n] = key;
  while(s[i] != key) {
    i++;
  }
  if(i == n)
    return 0;
  return 1;
}
