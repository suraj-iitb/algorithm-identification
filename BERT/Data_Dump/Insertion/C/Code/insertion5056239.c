#include <stdio.h>
#include <stdlib.h>

#define N 100

int main()
{
  int n, i, j, a[N], key;

  scanf("%d", &n);

  for(i = 0 ; i < n ; i++)
    {
      scanf("%d", a + i);
      if(a[i] < 0 || a[i] > 1000) exit(1);
    }

  for(i = 0 ; i < n - 1; i++)
    {
      printf("%d ", a[i]);
    }
  printf("%d", a[i]);
  printf("\n");

  for(i = 1 ; i <= n - 1 ; i++)
    {
      key = a[i];
      j = i - 1;

      while(j >= 0 && a[j] > key)
	{
	  a[j + 1] = a[j];
	  j--;
	}
      a[j + 1] = key;

      for(j = 0 ; j < n - 1; j++)
	{
	  printf("%d ", a[j]);
	}
      printf("%d", a[j]);
      printf("\n");
    }

  return 0;
}

