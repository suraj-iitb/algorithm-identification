
#include<stdio.h>
#include <math.h>
int binary_search (int a, int b[], int n);
int
main (void)
{

  int i, j, n, q, count = 0;

  int S[100000], T[50000];

  scanf ("%d", &n);
  for (i = 0; i < n; i++)
    {
      scanf ("%d", &S[i]);
    }

  scanf ("%d", &q);
  for (i = 0; i < q; i++)
    {
      scanf ("%d", &T[i]);
    }

  for (int i = 0; i < q; i++)
    {
      if (binary_search (T[i], S, n))
	{
	  count++;
	}
    }
  printf ("%d\n", count);


  return 0;

}

int
binary_search (int a, int b[], int n)
{
  int left = 0;
  int right = n;
  int mid;
  while (left < right)
    {
      mid = (left + right) / 2;
      
      if (b[mid] == a)
	{
	  return 1;
	}
      else if (a < b[mid])
	{
	  right = mid;
	}
      else
	{
	  left = mid + 1;
	}
    }
  return 0;
}


