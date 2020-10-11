#include <stdio.h>

int main()
{
  int n,i,j,g,min,koukan,kaisu=0;

  scanf("%d",&n);

  int S[n];

  for(i=0;i<n;i++)scanf("%d",&S[i]);
  for(i=0;i<n;i++)
    {
      
      min=i;
      
      for(j=i+1;j<n;j++)
	{
	  if(S[j]<S[min])
	    {
	      min=j;
	    }
	}
      if(min!=i)
	{
	  koukan=S[min];
	  S[min]=S[i];
	  S[i]=koukan;
	  kaisu++;
	}
    }
  
  for(i=0;i<n-1;i++)printf("%d ",S[i]);
  printf("%d\n%d\n",S[n-1],kaisu);
  return 0;
}

