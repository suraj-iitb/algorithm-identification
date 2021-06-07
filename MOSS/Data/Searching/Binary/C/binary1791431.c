#include <stdio.h>
#define N 100000

int BinarySearch(int, int *, int);

int main()
{
  int i, j;
  int n, q;
  int nl[N], s;
  int count = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++)
    {
      scanf("%d", &nl[i]);
    }

  scanf("%d", &q);
  for(i = 0; i < q; i++)
    {
      scanf("%d", &s);
      if(BinarySearch(n, nl, s) == 1) 
	{
	  count++;
	}
    }
  printf("%d\n", count);

  return 0;
}

int BinarySearch(int n, int *nl, int s)
{
  int left, mid, right;

  left = 0;
  right = n;
  mid = (left + right) / 2;

  while(nl[mid] != s)
    {
      if(left + 1 == right) return 0;
      if(nl[mid] < s) left = mid;
      else right = mid;

      mid = (left + right) / 2;
    }

  return 1;
}
