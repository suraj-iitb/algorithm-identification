#include<stdio.h>

int main()
{
  int n;
  int d[100];
  int temp;

  scanf("%d", &n);
  for(int i = 0 ; i < n; i++)
    {
      scanf("%d", &d[i]);
    }
  for(int i = 0 ; i < n; i++)
    {
      if(i == n-1)
	{
	  printf("%d", d[i]);
	  break;
	}
      printf("%d ", d[i]);
    }
  printf("\n");
  for(int i = 1; i < n; i++)
    {
      for(int j = 0; j < i; j++)
	{
	  if(d[i] < d[j])
	    {
	      temp = d[i];
	      d[i] = d[j];
	      d[j] = temp;
	    }
	}
      for(int k = 0; k < n; k++)
	{
	  if(k == n-1)
	    {
	      printf("%d", d[k]);
	      break;
	    }
	  printf("%d ", d[k]);
	}
      printf("\n");
    }
}

