#include<stdio.h>
#define N 100
main()
{
  int n,i,j,c[N],d,mini,count=0;
 
  scanf("%d",&n);
 
  for(i=0;i<n;i++)
    {
      scanf("%d",&c[i]);
    }
  for(i=0;i<n;i++)
    {
      mini = i;
      for(j=i;j<n;j++)
	{
	  if(c[j] < c[mini])
	    {
    
	      mini = j;
	    }
	}
      if(mini!=i)count++;
      d = c[i];
      c[i] = c[mini];
      c[mini] = d;
    }


for(i=0;i<n;i++)
  {
    if(i==n-1){printf("%d\n",c[i]);break;}
    printf("%d ",c[i]);
  }

 printf("%d\n",count);
return 0;
}
	  
