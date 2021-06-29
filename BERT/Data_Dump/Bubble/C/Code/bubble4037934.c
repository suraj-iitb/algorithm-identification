#include <stdio.h>

int main()
{
  int i,j,a[100],n,flag,tmp,cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
  flag = 1;
  i=0;
  while(flag==1)
    {
      flag = 0;
      for(j=n-1;j>i;j--)
	{
	  if(a[j]<a[j-1])
	    {
	      tmp = a[j];
	      a[j] = a[j-1];
	      a[j-1] = tmp;
	      cnt++;
	      flag = 1;
	    }
	}
      i++;
    }
  for(j=0;j<n;j++)
    {
      if(j!=0)printf(" ");
      printf("%d",a[j]);
    }
  printf("\n%d\n",cnt);

  return 0;
}

