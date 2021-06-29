#include <stdio.h>

int linearSearch(int *, int, int);

int main()
{
  int A[10001], n, q, key, i, m, sum=0;

  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d", &A[i]);

  scanf("%d", &q);
  for(i=0; i<q; i++)
  {
    scanf("%d", &key);
    m=linearSearch(A, n, key);
    if(m==1) sum++;
  }

  printf("%d\n", sum);

  return 0;
}

int linearSearch(int *A, int n, int key)
{
  int i=0;
  A[n]=key;

  while(A[i]!=key) i++;

  if(i==n) return 0;
  else return 1;
}

