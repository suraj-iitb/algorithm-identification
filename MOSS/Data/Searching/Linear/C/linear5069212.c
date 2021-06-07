#include<stdio.h>

int main()
{
  int i,j,count = 0;
  int n;
  int a[10001];
  int q;
  int b[500];

  scanf("%d",&n);
  for(i = 0; i < n; i++)
    {
      scanf("%d",&a[i]);
   
    }
  
  scanf("%d",&q);
  for(i = 0; i < q; i++)
    {
      scanf("%d",&b[i]);
   
    }

  for(i = 0; i < q; i++)
    {
      j = 0;
      a[n] = b[i];
    
      while(1)
	{
	  if(a[j] == b[i])
	    {
	     
	      if(j != n)count++;
	      break;
	    }
	  else j++;
	}
    }
  
  
  printf("%d\n",count);
  return 0;
}
  

