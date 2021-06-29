#include <stdio.h>

int main()
{
  int i,j,n,a[100],mn,tmp,cnt=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }

  for(i=0;i<n;i++)
    {
      mn = i;
      for(j=i;j<n;j++)
	{
	  if(a[j]<a[mn])mn = j;
	}
      if(a[mn]!=a[i])
	{
	  tmp = a[mn];
	  a[mn] = a[i];
	  a[i] = tmp;
	  cnt++;
	}
    }
  for(i=0;i<n;i++)
    {
      if(i!=0)printf(" ");
      printf("%d",a[i]);
    }
  printf("\n%d\n",cnt);

  return 0;
}

