#include<stdio.h>
main()
{
  int n,c[100],i,flag,l,k,d,ccount=0;
 
  scanf("%d",&n);
 
  for(i=0;i<n;i++)
    {
      scanf("%d",&c[i]);
    }
 
  flag = 1;
  k = 0;
  while(flag)
    {
      flag =0; 
      for(i=n-1;i>=k+1;i--)
	{
	  
	  if(c[i-1] > c[i]){
	    d = c[i];
	    c[i] = c[i-1];
	    c[i-1] = d;
	    flag = 1;
	    ccount++;
          }
	  
	}
      k++;
      
    }
     
 for(l=0;l<n;l++)
    {
      printf("%d",c[l]);
      if(l!=n-1) printf(" ");
    }
      printf("\n%d\n",ccount);
      return 0;
 
 
    }
