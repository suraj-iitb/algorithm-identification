#include<stdio.h>
int main()
{
  int i,j,k,minj,a[100],n,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  for(i=0;i<n;i++)
    {
      minj=i;
      for(j=i;j<n;j++)
	{
	  if(a[j]<a[minj]) minj=j;
	}
      if(i!=minj)
	{
	  k=a[i];
	  a[i]=a[minj];
	  a[minj]=k;
	  count++;
	}
    }
  for(i=0;i<n-1;i++) printf("%d ",a[i]);
  printf("%d\n%d\n",a[i],count);
  return 0;
}
