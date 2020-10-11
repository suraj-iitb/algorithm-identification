#include<stdio.h>
#define N 100
main()
{
  int A[N],i,v,j,n,x;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
      if(i==n-1)printf("%d",A[i]);
      else printf("%d ",A[i]);
      }
  printf("\n");
  for(i=1;i<=n;i++)
    {
      if(i>1){   
for(x=0;x<n;x++)
	{
	  if(x==n-1)printf("%d",A[x]);
	  else printf("%d ",A[x]);
	}
      printf("\n");
      }
    
  v=A[i];
  j=i-1;
  while(j>=0&&A[j]>v)
    {
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
     
    }
    }
  return 0;
}
