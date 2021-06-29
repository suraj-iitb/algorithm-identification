#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i,j,tmp;
  
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
      if(a[i] < 0 || a[i] > 1000)
	{
	  printf("Error\n");
	  exit(2);
	}
    }
  for(i = 0; i < n; i++)
    {
      printf("%d",a[i]);
	     if(i != n-1)printf(" ");
	     else printf("\n");
	     }
 
	for(i = 1; i < n; i++)
	  {
	    tmp = a[i];
	    j = i-1;
	    while(j >= 0 && a[j] > tmp)
	      {
		a[j+1] = a[j];
		j--;
		a[j+1] = tmp;
	      }
	    for(j = 0; j < n; j++)
	      {
		printf("%d",a[j]);
		if(j != n-1)printf(" ");
		else printf("\n");
	      }
	  }
	return 0;
}

  
  

