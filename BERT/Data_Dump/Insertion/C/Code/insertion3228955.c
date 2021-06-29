#include<stdio.h>
int main(void)
{
  int n, r[100], i, j, key;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&r[i]);
  }
  for(j=0;j<n-1;j++)
  {
    printf("%d ",r[j]);
  }
  printf("%d\n",r[j]);
  for(i=1;i<n;i++)
  {
    key = r[i];
    for(j=i-1;j>=0;j--)
    {
      if(key > r[j]) break;
      else r[j+1] = r[j];
    }
    r[j+1] =key;
    for(j=0;j<n-1;j++)
    {
      printf("%d ",r[j]);
    }
    printf("%d\n",r[j]);
  }
  return 0;
}
