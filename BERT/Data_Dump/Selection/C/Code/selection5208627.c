#include<stdio.h>

int main()
{
  int i,j,n,min,t;
  int count=0;
  int a[100];

  scanf("%d",&n);
  for(i=0;i<n;i++) 
  {
      scanf("%d",&a[i]);
  }
  
  for(i=0;i<n-1;i++)
  {
    min=i;
    for(j=i;j<n;j++)
    {
      if(a[j]<a[min])min=j;
    }
    t=a[i];
    a[i]=a[min];
    a[min]=t;
    if(i!=min) count++;
  }

  
  for(i=0;i<n-1;i++) 
  {
      printf("%d ",a[i]);
  }
  printf("%d\n",a[n-1]);
  printf("%d\n",count);

  return 0;
}


