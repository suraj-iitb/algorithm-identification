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
  int temp;
  int count=0;
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-1;j++)
    {
      if(a[j]>a[j+1])
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
        count++;
      }
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

