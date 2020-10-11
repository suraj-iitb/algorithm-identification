#include <stdio.h>

int main()
{
  int a[100001],n,i,n1,j,flag;
  for(i=0;i<=10001;i++)
  {
    a[i]=0;
  }
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    scanf("%d",&n1);
    a[n1]++;
  }
  for(i=0;i<=10001;i++)
  {
    if(i==0)flag=0;
    for(j=a[i];j>0;j--)
    {
      if(flag==1)
      {
        printf(" ");
      }
      else flag=1;
      printf("%d",i);
    }
  }
  printf("\n");
  return 0;
}
