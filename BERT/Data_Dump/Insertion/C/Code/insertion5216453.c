#include<stdio.h>
int main(void)
{
  int v,n,a[1000];
  int i,j,t;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }

  for(i=0;i<n;i++)
    {
      v=a[i];
      j=i-1;
      while(j>=0&&a[j]>v)
        {
          a[j+1]=a[j];
          j--;
        }
      a[j+1]=v;

      for(t=0;t<n;t++)
        {
          if(t==n-1){printf("%d",a[t]);}
          else{
            printf("%d ",a[t]);
          }
        }
      printf("\n");
    }
  return 0;
}
