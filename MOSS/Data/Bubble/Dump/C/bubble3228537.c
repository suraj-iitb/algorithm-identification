#include<stdio.h>

int main()
{
  int n;
  int d[100];
  int temp;
  int count = 0;
  int i = 0;
  
  scanf("%d", &n);
  for(int i = 0 ; i < n; i++)
    {
      scanf("%d", &d[i]);
    }
  while(1)
    {
      if(i == n-1)
	{
	  break;
	}
      if(d[i] > d[i+1])
	{
	  temp = d[i];
	  d[i] = d[i+1];
	  d[i+1] = temp;
	  i = 0;
	  count++;
	  continue;
	}
      i++;
    }
  for(int i = 0 ; i < n; i++)
    {
      if(i == n-1)
	{
	  printf("%d\n", d[i]);
	  break;
	}
      printf("%d ", d[i]);
    }
  printf("%d\n", count);
}

