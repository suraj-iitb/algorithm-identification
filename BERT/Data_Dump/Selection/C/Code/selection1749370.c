#include<stdio.h>

int main()
{
  int length;
  int n[100];
  int i, j, min_i;
  int tmp;
  int count = 0;

  scanf("%d", &length);
  for(i = 0; i < length; i++)
    {
      scanf("%d",&n[i]);
    }
  
  for(i = 0; i < length; i++)
    {
      min_i = i;
      for(j = i; j < length; j++)
	{
	  if(n[j] < n[min_i]) min_i = j;
	}
      if(i != min_i)
	{
	  tmp = n[i];
	  n[i] = n[min_i];
	  n[min_i] = tmp;
	  count++;
	}
    }

  for(i = 0; i < length - 1; i++)
    {
      printf("%d ", n[i]);
    }
  printf("%d\n%d\n", n[length - 1], count);

  return 0;
}
