#include<stdio.h>
int main(void)
{
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  int min;
  int temp;
  int count=0;
  for(int i=0;i<n;i++)
  {
    min=i;
    for(int j=i;j<n;j++)
    {
      if(a[j]<a[min])
      {
        min=j;
      }
    }
  	if(a[min]<a[i])
  	{
  		temp=a[i];
        a[i]=a[min];
        a[min]=temp;
        count++;
  	}
  }
  for(int i=0;i<n-1;i++)
  {
    printf("%d ",a[i]);
  }
  printf("%d",a[n-1]);
  printf("\n");
  printf("%d\n",count);
  return 0;
}

