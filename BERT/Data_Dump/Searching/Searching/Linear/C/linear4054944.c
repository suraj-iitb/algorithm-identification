#include <stdio.h>

int a[10000],b[10000],n1,n2;
int main()
{
  int i=0,key,cnt=0,j;
  scanf("%d",&n1);
  for(i=0;i<n1;i++)
    {
      scanf("%d",&a[i]);
    }
  scanf("%d",&n2);
  for(i=0;i<n2;i++)
    {
      scanf("%d",&b[i]);
    }
  for(i=0;i<n2;i++)
    {
      a[n1] = b[i];
      j=0;
      while(a[j]!=a[n1])
	{
	  j++;
	}
      if(j==n1)continue;
      else
	{
	  cnt++;
	  continue;
	}
    }
  printf("%d\n",cnt);
  return 0;
}



