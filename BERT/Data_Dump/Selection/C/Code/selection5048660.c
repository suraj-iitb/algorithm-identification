#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i,j,minj,cnt = 0,tmp;
  int n;
  scanf("%d",&n);
  if(n < 1 || n > 100)
    {
      printf("Error\n");
      exit(1);
    }

  int a[n];
  for(i = 0; i < n; i++)
    {
      scanf("%d",&a[i]);
      if(a[i] < 0 || a[i] > 100)
	{
	  printf("Error\n");
	  exit(2);
	}
    }

  for(i = 0; i < n; i++)
    {
      minj = i;
      for(j = i; j < n; j++)
	{
	  if(a[j] < a[minj])
	    {
	      minj = j;
	      
	    }
	}
      if(i != minj)
	{
	  tmp = a[i];
	  a[i] = a[minj];
	  a[minj] = tmp;
	  cnt++;
	}
	  
	    
	    }
    
   for(i = 0; i < n; i++)
    {
      printf("%d",a[i]);
      if(i == n-1)printf("\n");
      else printf(" ");
    }
  printf("%d\n",cnt);
  
  return 0;
}

	  

