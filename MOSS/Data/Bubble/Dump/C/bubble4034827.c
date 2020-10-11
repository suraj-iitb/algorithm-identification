#include <stdio.h>


int main()
{
  int n[100],a,i,b,k=0,c=0,flag=1;
  scanf("%d",&a);
  for(i=0;i<a;i++) scanf("%d",&n[i]);
  while(flag)
    {
      flag = 0;
      for(b=a-1;b>=1;b--)
	{
	  if(n[b]<n[b-1])
	    {
	      k=n[b];
	      n[b]=n[b-1];
	      n[b-1]=k;
	      flag = 1;
	      c++;
	    }
	}
    }
  for(i=0;i<a-1;i++) printf("%d ",n[i]);
  printf("%d\n",n[i]);
  printf("%d\n",c);
  return 0;
}

