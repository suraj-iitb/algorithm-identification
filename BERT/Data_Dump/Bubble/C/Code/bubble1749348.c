#include<stdio.h>

int main()
{
  int length;
  int n[100];
  int i,j;
  int tmp;
  int flag;
  int count = 0;

  scanf("%d", &length);
  for(i = 0; i < length; i++)
    {
      scanf("%d",&n[i]);
    }
  
  for(i = 0; i < length; i++)
    {
      flag = 0;
      for(j = length - 1; j > i; j--)
	{
	  if(n[j - 1] > n[j]) 
	    {
	      tmp = n[j];
	      n[j] = n[j - 1];
	      n[j - 1] = tmp;
	      flag = 1;
	      count++;
	    }
	}
      if(flag == 0) break;
    }

  for(i = 0; i < length - 1; i++)
    {
      printf("%d ", n[i]);
    }
  printf("%d\n%d\n", n[length - 1], count);

  return 0;
}
