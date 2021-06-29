#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n,*a,count=0;
  int i,j,t,k;

  
  scanf("%d",&n);

  a = (int *)malloc(n * sizeof(int));

  for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }

  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  if(a[j] < a[j-1])
	    {
	      t = a[j-1];
	      k = a[j];
	      a[j] = t;
	      a[j-1] = k;
	      count++;
	    }
	 
	 
	}
      
    }
   for(j=0;j<n;j++)
     {
       if (j != 0) printf(" ");
       printf("%d",a[j]);
     }
     printf("\n");
 
  printf("%d\n",count);
  
  return 0;
}

