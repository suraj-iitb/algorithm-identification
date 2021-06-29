#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n,*a,count=0;
  int i,j,t,k,minj;

  
  scanf("%d",&n);

  a = (int *)malloc(n * sizeof(int));

  for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }

  for(i=0;i<n;i++)
    {
      minj = i;
      for(j=i;j<n;j++)
	{
	  if(a[j] < a[minj])
	    {
	      minj = j;
	     
	    }
	  
	}
      if(i != minj)
	{
         t = a[minj];
	 k = a[i];
	 a[i] = t;
	 a[minj] = k;
	 count++;
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

