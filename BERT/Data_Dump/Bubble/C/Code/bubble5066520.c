#include<stdio.h>

int main()
{
  int i, j, n, flag = 1, tmp, c = 0;

  scanf("%d",&n);
  int a[n];
  for(i = 0 ;i < n;i++)scanf("%d",&a[i]);
  while(flag == 1)
  {
    flag = 0;
    for(j = n-1;j != 0;j--)
    {
      if(a[j] < a[j-1])
      {
        tmp = a[j-1];
        a[j-1] = a[j];
        a[j] = tmp;
        c++;
        flag = 1;
      }
    }
  }
  for(i = 0;i < n-1;i++)printf("%d ",a[i]);
  printf("%d\n",a[n-1]);
  printf("%d\n",c);
  return 0;
}

