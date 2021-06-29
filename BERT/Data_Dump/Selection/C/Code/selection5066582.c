#include<stdio.h>

int main()
{
  int i, j, n, minj,tmp,c = 0;
  scanf("%d",&n);
  int a[n];
  for(i = 0;i < n;i++)scanf("%d",&a[i]);
  for(i = 0;i < n;i++)
  {
    minj = i;
    for(j = i;j < n;j++)
    {
      if(a[j] < a[minj])minj = j;
    }
    if(i != minj)c++;
    tmp = a[i];
    a[i] = a[minj];
    a[minj] = tmp;
  }
  for(i = 0;i < n-1;i++)printf("%d ",a[i]);
  printf("%d\n",a[n-1]);
  printf("%d\n",c);
  return 0;
}

